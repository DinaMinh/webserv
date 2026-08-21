/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminh <dminh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 11:00:47 by dminh             #+#    #+#             */
/*   Updated: 2026/08/21 11:04:38 by dminh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASocket.class.hpp"
#include "Server.class.hpp"

Server::Server(const std::string &port, const std::string &pass)
:	ASocket(port, pass)
{
}

Server::Server(const Server &cpy)
:	ASocket(cpy._port, cpy._pass)
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
		throw	std::runtime_error("error: Couldn't bind the socket.");
}

Server::~Server(void)
{
}

