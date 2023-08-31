/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:00:27 by trobert           #+#    #+#             */
/*   Updated: 2023/02/07 12:30:39 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *tab, unsigned int const sizeTab, void (*function)(T &))
{
	for (unsigned int i(0); i < sizeTab; i++)
	{
		function(tab[i]);
	}
}

#endif