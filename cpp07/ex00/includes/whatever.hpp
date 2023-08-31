/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:00:27 by trobert           #+#    #+#             */
/*   Updated: 2023/02/09 13:23:10 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp; 
}

template <typename T>
T const &max(T const &a, T const &b)
{
	return ((a > b) ? a : b);
}

template <typename T>
T &max(T &a, T &b)
{
	return ((a > b) ? a : b);
}

template <typename T>
T const &min(T const &a, T const &b)
{
	return ((a < b) ? a : b);
}

template <typename T>
T &min(T &a, T &b)
{
	return ((a < b) ? a : b);
}


#endif