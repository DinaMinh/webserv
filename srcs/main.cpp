/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminh <dminh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 08:55:37 by dminh             #+#    #+#             */
/*   Updated: 2026/08/21 13:44:09 by dminh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.hpp"

void	checkParams(int ac, char **av)
{
	int	port;

	if (ac != 3)
		throw (ParametersException(WRONG_PARAMS));
	for (size_t i = 0; av[1][i]; i++)
		if (!std::isdigit(av[1][i]))
			throw (ParametersException("error: Invalid port."));
	port = atoi(av[1]);

	if (port < 0 || port > 65535)
		throw (ParametersException("error: Invalid port."));
}
int	main(int ac, char **av)
{
	try
	{
		checkParams(ac, av);
		std::cout << "port = " << av[1] << ", client = " << av[2] << std::endl;
		Server	sock(av[1], av[2]);
		sock.establishConnection();
		std::string	msg;
		while (sock.getRun())
		{
			std::getline(std::cin, msg);
			if (msg == "leave")
				sock.setRun(false);
		}
	}
	catch (std::exception &e)
	{ std::cout << e.what() << std::endl; }
	return (0);
}
