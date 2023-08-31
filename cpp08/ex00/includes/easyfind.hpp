/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:22:51 by trobert           #+#    #+#             */
/*   Updated: 2023/02/11 14:39:23 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>

class NotFoundException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("integer not found");
		}
};

template <typename T>
typename T::iterator easyfind(T container, const int toFind)
{
	typename T::iterator iter = std::find(container.begin(), container.end(), toFind);
	if (iter != container.end())
		return iter;
	else
		throw NotFoundException();
}

#endif