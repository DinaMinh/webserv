/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminh <dminh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 11:46:05 by dminh             #+#    #+#             */
/*   Updated: 2026/09/11 13:15:32 by dminh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CLIENT_CLASS_HPP
# define CLIENT_CLASS_HPP

# include <iostream>
# include <unistd.h>

class	Client
{
	private:
		std::string	_buf;
		std::string	_username;
		std::string	_nickname;
		std::string	_ip;
		int			_fd;
	public:
		Client(int socket);
		Client(const Client &cpy);
		~Client(void);
		Client	&operator=(const Client &src);
};

#endif
