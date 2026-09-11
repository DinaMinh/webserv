/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminh <dminh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 11:46:46 by dminh             #+#    #+#             */
/*   Updated: 2026/09/11 16:03:08 by dminh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.class.hpp"

Client::Client(int socket)
:	_fd(socket)
{
}

Client::Client(const Client &cpy)
:	_buf(cpy._buf), _username(cpy._username), _nickname(cpy._nickname),
	_ip(cpy._ip), _fd(cpy._fd)
{
}

Client	&Client::operator=(const Client &src)
{
	if (this != &src)
	{
		this->_buf = src._buf;
		this->_username = src._username;
		this->_nickname = src._nickname;
		this->_ip = src._ip;
		this->_fd = src._fd;
	}
	return (*this);
}

Client::~Client(void)
{
}

