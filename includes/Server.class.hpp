/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminh <dminh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 10:58:04 by dminh             #+#    #+#             */
/*   Updated: 2026/09/11 15:38:40 by dminh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SERVER_CLASS_HPP
# define SERVER_CLASS_HPP

# include <iostream>
# include <map>
# include <fcntl.h>
# include <sys/epoll.h>

# define MAX_EVENTS 64
# define DATA_SIZE 512

/* Forward declarations of ASocket and Client */
class	ASocket;
class	Client;

typedef std::map<int, Client>::iterator	mapIt;

class	Server : public ASocket
{
	private:
		std::map<int, Client>	_clients;
		char					_buf[DATA_SIZE];
		int						_serv_fd;
		int						_accept_sock;
		int						_bytes;
		int						_epoll_fd;
	public:
		Server(const std::string &port, const std::string &pass);
		Server(const Server &cpy);
		~Server(void);
		Server	&operator=(const Server &src);
		void	establishConnection(void);
		void	run(void);
		void	closeFd(void);
		void	acceptClient(void);
		void	receiveData(int client_fd);
};

#endif

