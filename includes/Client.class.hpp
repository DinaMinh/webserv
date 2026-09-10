/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminh <dminh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 11:46:05 by dminh             #+#    #+#             */
/*   Updated: 2026/09/10 13:13:49 by dminh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CLIENT_CLASS_HPP
# define CLIENT_CLASS_HPP

# include <iostream>

class	ASocket;

class	Client : public ASocket
{
	private:
		int					_client_fd;
	public:
		Client(const std::string &port, const std::string &pw);
		Client(const Client &cpy);
		~Client(void);
		Client	&operator=(const Client &src);
		void	establishConnection(void);
		void	closeFd(void);
};

#endif

