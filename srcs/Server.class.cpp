/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminh <dminh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 11:00:47 by dminh             #+#    #+#             */
/*   Updated: 2026/09/11 16:03:53 by dminh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASocket.class.hpp"
#include "Client.class.hpp"
#include "Server.class.hpp"

Server::Server(const std::string &port, const std::string &pw)
:	ASocket(port, pw)
{
	if ((this->_serv_fd = socket(DOMAIN, TYPE, PROTOCOL)) == 0)
		throw	std::runtime_error("error: Couldn't open the socket.");
	std::cout << "serv fd = " << this->_serv_fd << std::endl;
	int	flags = fcntl(this->_serv_fd, F_GETFL, 0);
	if (flags == -1)
		throw	std::runtime_error("error: Couldn't get the socket flags.");
	flags = flags | O_NONBLOCK;
	if (fcntl(this->_serv_fd, F_SETFL, flags) == -1)
		throw	std::runtime_error("error: Couldn't set the socket flags");
}

Server::Server(const Server &cpy)
:	ASocket(cpy._port, cpy._pw)
{}

Server	&Server::operator=(const Server &src)
{
	if (this != &src){}
	return (*this);
}

void	Server::establishConnection(void)
{
	std::memset(&this->_addr, 0, sizeof(this->_addr));
	this->_addr.sin_family = AF_INET;
	this->_addr.sin_addr.s_addr = INADDR_ANY;
	this->_addr.sin_port = htons(atoi(this->_port.c_str()));
	if (bind(this->_serv_fd, (sockaddr *)&_addr, sizeof(_addr)) < 0)
		throw std::runtime_error("error: Couldn't bind the socket.");
	if (listen(this->_serv_fd, 1) != 0)
		std::cout << "Couldn't start listening." << std::endl;
	else
		std::cout << "Listening." << std::endl;
	this->_epoll_fd = epoll_create1(0);
	if (this->_epoll_fd == -1)
		throw	std::runtime_error("error: Couldn't create the epoll");
	struct epoll_event	ev;

	std::memset(&ev, 0, sizeof(ev));
	ev.events = EPOLLIN;
	ev.data.fd = this->_serv_fd;
	if (epoll_ctl(this->_epoll_fd, EPOLL_CTL_ADD, this->_serv_fd, &ev) == -1)
		throw std::runtime_error("error: Couldn't add server fd to epoll");
}

void	Server::run(void)
{
	struct epoll_event	events[MAX_EVENTS];
	int	fds;
	while (this->_running)
	{
		fds = epoll_wait(this->_epoll_fd, events, MAX_EVENTS, -1);
		if (fds < 0)
		{
			if (errno == EINTR)
				continue;
			throw std::runtime_error("error: epoll_wait failed");
		}
		for (int i = 0; i < fds; i++)
		{
			if (events[i].data.fd == this->_serv_fd)
				this->acceptClient();
			else
				this->receiveData(events[i].data.fd);
		}
	}
}

void	Server::acceptClient(void)
{
	this->_accept_sock = accept(this->_serv_fd, NULL, NULL);
	if (this->_accept_sock == -1)
		throw std::runtime_error("error: Couldn't accept the connection");
	else
	{
		std::cout << "Connection accepted !" << std::endl;
		int flags = fcntl(this->_accept_sock, F_GETFL, 0);
		if (fcntl(this->_accept_sock, F_SETFL, flags | O_NONBLOCK) == - 1)
			throw	std::runtime_error("error: Couldn't set the socket flags");
		this->_clients.insert(std::make_pair(this->_accept_sock,
					Client(this->_accept_sock)));
		struct epoll_event ev;

		std::memset(&ev, 0, sizeof(ev));
		ev.events = EPOLLIN;
		ev.data.fd = this->_accept_sock;
	if (epoll_ctl(this->_epoll_fd, EPOLL_CTL_ADD, this->_accept_sock,
			&ev) == -1)
		throw std::runtime_error("error: Couldn't add client fd to epoll");
	}
}

void	Server::receiveData(int client_fd)
{
	this->_bytes = recv(client_fd, this->_buf, DATA_SIZE - 1, 0);
	if (this->_bytes <= 0)
	{
		epoll_ctl(this->_epoll_fd, EPOLL_CTL_DEL, client_fd, NULL);
		for (mapIt it = this->_clients.begin(); it != this->_clients.end();
				++it)
		{
			if (it->first == client_fd)
			{
				this->_clients.erase(it);
				break ;
			}
		}
		close(client_fd);
	}
	else
	{
		this->_buf[this->_bytes] = '\0';
		std::cout << this->_buf;
	}
}

void	Server::closeFd(void)
{
	close(this->_serv_fd);
}

Server::~Server(void)
{
}

