/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminh <dminh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 11:00:47 by dminh             #+#    #+#             */
/*   Updated: 2026/09/10 13:09:10 by dminh            ###   ########.fr       */
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
	int	accept_sock;
	this->_addr.sin_family = AF_INET;
	this->_addr.sin_addr.s_addr = INADDR_ANY;
	this->_addr.sin_port = htons(atoi(this->_port.c_str()));
	if (bind(this->_serv_fd, (sockaddr *)&_addr, sizeof(_addr)) < 0)
		throw std::runtime_error("error: Couldn't bind the socket.");
	if (listen(this->_serv_fd, 1) != 0)
		std::cout << "Couldn't start listening." << std::endl;
	else
		std::cout << "Listening." << std::endl;
	accept_sock = accept(this->_serv_fd, NULL, NULL);
	if (accept_sock == -1)
		throw std::runtime_error("error: Couldn't accept the connection");
	else
		std::cout << "Connection accepted !" << std::endl;
}

void	Server::closeFd(void)
{
	close(this->_serv_fd);
}

Server::~Server(void)
{
}

