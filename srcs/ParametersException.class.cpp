/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParametersException.class.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminh <dminh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 16:10:42 by dminh             #+#    #+#             */
/*   Updated: 2026/08/20 16:10:42 by dminh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParametersException.class.hpp"

ParametersException::ParametersException(const char *err)
:	_err(err)
{}

const char	*ParametersException::what() const throw()
{
	return (this->_err);
}
