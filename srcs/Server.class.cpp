/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminh <dminh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 11:00:47 by dminh             #+#    #+#             */
/*   Updated: 2026/09/10 15:33:16 by dminh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASocket.class.hpp"
#include "Server.class.hpp"

Server::Server(const std::string &port, const std::string &pw)
:	ASocket(port, pw)
{
	if ((this->_serv_fd = socket(DOMAIN, TYPE, PROTOCOL)) == 0)
		throw	std::runtime_error("error: Couldn't open the socket.");
	std::cout << "serv fd = " << this->_serv_fd << std::endl;
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
	memset(&this->_addr, 0, sizeof(this->_addr));
	this->_addr.sin_family = AF_INET;
	this->_addr.sin_addr.s_addr = INADDR_ANY;
	this->_addr.sin_port = htons(atoi(this->_port.c_str()));
	if (bind(this->_serv_fd, (sockaddr *)&_addr, sizeof(_addr)) < 0)
		throw std::runtime_error("error: Couldn't bind the socket.");
	if (listen(this->_serv_fd, 1) != 0)
		std::cout << "Couldn't start listening." << std::endl;
	else
		std::cout << "Listening." << std::endl;
		
}

void	Server::receiveData(void)
{
	this->_accept_sock = accept(this->_serv_fd, NULL, NULL);
	if (this->_accept_sock == -1)
		throw std::runtime_error("error: Couldn't accept the connection");
	else
		std::cout << "Connection accepted !" << std::endl;
	this->_bytes = recv(_accept_sock, _buf, 200, 0);
	if (_bytes < 0)
		throw std::runtime_error("error: Couldn't receive data");
	else
		std::cout<< "Received : " << _buf << std::endl;
}

void	Server::closeFd(void)
{
	close(this->_serv_fd);
}

int	Server::getAcceptSock(void) const
{
	return (this->_accept_sock);
}

Server::~Server(void)
{
}

