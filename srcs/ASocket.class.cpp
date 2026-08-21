/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASocket.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminh <dminh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 16:48:06 by dminh             #+#    #+#             */
/*   Updated: 2026/08/21 13:52:46 by dminh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASocket.class.hpp"

ASocket::ASocket(const std::string &port, const std::string &pass)
:	_host(LOC_HOST), _port(port), _pass(pass), _running(true)
{
	if ((this->_serv_fd = socket(DOMAIN, TYPE, PROTOCOL)) == 0)
		throw	std::runtime_error("error: Couldn't open the socket.");
	std::cout << "serv fd = " << this->_serv_fd << std::endl;
}

ASocket::ASocket(const ASocket &cpy)
{
	(void)cpy;
}

ASocket	&ASocket::operator=(const ASocket &src)
{
	if (this != &src)
	{}
	return (*this);
}

void	ASocket::closeFd(void)
{
	close(this->_serv_fd);
}

bool	ASocket::getRun(void) const
{
	return (this->_running);
}

void	ASocket::setRun(bool val)
{
	this->_running = val;
}

ASocket::~ASocket(void)
{}

