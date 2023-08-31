/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:17:20 by trobert           #+#    #+#             */
/*   Updated: 2022/12/17 13:39:13 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void) 
{
	// Fixed a;
	// Fixed c(1.0f);
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << c++ << std::endl;
	// std::cout << c << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;

	////////////////////////////////////////////////////////////////////////

	Fixed const a( Fixed(1.5f) + Fixed(1.5f));
	Fixed const b( Fixed(2.0f) * Fixed(3.0f));
	Fixed c;
	Fixed const d (9);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	c = a + b;
	std::cout << "c = " << c << std::endl;
	c++;
	if (c == b)
		std::cout << "c and b are equals" << std::endl;
	else
		std::cout << "c and b are not equals" << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout 
		<< "the greater between "
		<< c << " and "
		<< d << " is "
		<< Fixed::max(c, d) << std::endl;
	return 0;
}