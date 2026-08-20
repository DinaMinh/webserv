/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParametersException.class.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminh <dminh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 16:08:12 by dminh             #+#    #+#             */
/*   Updated: 2026/08/20 16:08:12 by dminh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PARAMETERSEXCEPTION_CLASS_HPP
# define PARAMETERSEXCEPTION_CLASS_HPP

# include <exception>

class	ParametersException : public std::exception
{
	private:
		const char	*_err;
	public:
		ParametersException(const char *err);
		const char	*what() const throw();
};

#endif

