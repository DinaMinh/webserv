/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminh <dminh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 11:46:46 by dminh             #+#    #+#             */
/*   Updated: 2026/09/10 14:36:02 by dminh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASocket.class.hpp"
#include "Client.class.hpp"

Client::Client(const std::string &port, const std::string &pw)
:	ASocket(port, pw)
{
	if ((this->_client_fd = socket(DOMAIN, TYPE, PROTOCOL)) == 0)
		throw	std::runtime_error("error: Couldn't open the socket.");
}

Client::Client(const Client &cpy)
:	ASocket(cpy._port, cpy._pw)
{
}

Client	&Client::operator=(const Client &src)
{
	if (this != &src)
	{
	}
	return (*this);
}

void	Client::establishConnection(void)
{
	memset(&this->_addr, 0, sizeof(this->_addr));
	this->_addr.sin_family = AF_INET;
	this->_addr.sin_addr.s_addr = INADDR_ANY;
	this->_addr.sin_port = htons(atoi(this->_port.c_str()));
	if (connect(this->_client_fd, (sockaddr *)&this->_addr,
			sizeof(this->_addr)) < 0)
		throw std::runtime_error("error: Couldn't connect to server");
	else
		std::cout << "Connection OK" << std::endl;
	return ;
}

void	Client::closeFd(void)
{
	return ;
}

Client::~Client(void)
{
}

