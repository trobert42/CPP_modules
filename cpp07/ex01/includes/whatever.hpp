/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:00:27 by trobert           #+#    #+#             */
/*   Updated: 2023/02/09 13:35:06 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T const &a, T const &b)
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
T &max(T const &a, T const &b)
{
	return ((a >= b) ? a : b);
}

template <typename T>
T const &min(T const &a, T const &b)
{
	return ((a < b) ? a : b);
}

template <typename T>
T &min(T const &a, T const &b)
{
	return ((a <= b)? a : b);
}

template <typename T>
void increment(T &arg)
{
	arg++;
}

#endif