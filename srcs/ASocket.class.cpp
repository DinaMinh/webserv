/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASocket.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminh <dminh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 16:48:06 by dminh             #+#    #+#             */
/*   Updated: 2026/09/10 11:46:02 by dminh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASocket.class.hpp"

ASocket::ASocket(const std::string &port, const std::string &pw)
:	_host(LOC_HOST), _port(port), _pw(pw), _running(true)
{
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

bool	ASocket::getRun(void) const
{
	return (this->_running);
}

void	ASocket::setRun(bool val)
{
	this->_running = val;
	if (!this->_running)
		this->closeFd();
}

ASocket::~ASocket(void)
{}

