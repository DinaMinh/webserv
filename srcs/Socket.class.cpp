/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminh <dminh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 16:48:06 by dminh             #+#    #+#             */
/*   Updated: 2026/08/20 18:49:34 by dminh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Socket.class.hpp"

Socket::Socket(const std::string &port, const std::string &pass)
:	_host(LOC_HOST), _port(port), _pass(pass)
{
	(void)port, (void)pass;
	if ((this->_sock = socket(DOMAIN, TYPE, PROTOCOL) < 0))
		throw	std::runtime_error("error: Couldn't open the socket.");
	std::cout << "sock = " << this->_sock << std::endl;
	memset(&this->_addr, 0, sizeof(this->_addr));
	this->_addr.sin_family = AF_INET;
	this->_addr.sin_addr.s_addr = INADDR_ANY;
	this->_addr.sin_family = htons(atoi(_port.c_str()));
	if (bind(_sock, (sockaddr *)&_addr, sizeof(_addr)) < 0)
		throw	std::runtime_error("error: Couldn't bind the socket.");
}

Socket::Socket(const Socket &cpy)
{
	(void)cpy;
}

Socket	&Socket::operator=(const Socket &src)
{
	if (this != &src)
	{}
	return (*this);
}

Socket::~Socket(void)
{}

