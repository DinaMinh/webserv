/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminh <dminh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 16:47:52 by dminh             #+#    #+#             */
/*   Updated: 2026/08/20 18:30:22 by dminh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SOCKET_CLASS_HPP
# define SOCKET_CLASS_HPP

# include <iostream>
# include <sys/socket.h>
# include <exception>
# include <netinet/in.h>
# include <cstdlib>
# include <cstring>

/*	AF_INET: Ipv4
 *	SOCK_STREAM: TCP
 *	PROTOCOL is 0 because usually, only one protocol exists 
 *	LOC_HOST is the default local host ip */

# define DOMAIN AF_INET
# define TYPE SOCK_STREAM
# define PROTOCOL 0
# define LOC_HOST "127.0.0.1"

class	Socket
{
	private:
		Socket(const Socket &cpy);
		Socket	&operator=(const Socket &src);
		const std::string	_host;
		const std::string	_port;
		const std::string	_pass;
		struct sockaddr_in	_addr;
		int					_sock;
	public:
		Socket(const std::string &port, const std::string &pass);
		~Socket(void);
};

#endif

