/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminh <dminh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 10:58:04 by dminh             #+#    #+#             */
/*   Updated: 2026/08/21 10:58:04 by dminh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SERVER_CLASS_HPP
# define SERVER_CLASS_HPP

# include <iostream>

class	ASocket;

class	Server : public ASocket
{
	private:
	public:
		Server(const std::string &port, const std::string &pass);
		Server(const Server &cpy);
		~Server(void);
		Server	&operator=(const Server &src);
		void	establishConnection(void);
};

#endif

