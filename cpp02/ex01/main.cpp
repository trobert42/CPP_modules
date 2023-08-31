/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:54:30 by trobert           #+#    #+#             */
/*   Updated: 2022/12/20 14:01:35 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a; //can't do Fixed a(10), it has to be constant
	Fixed b;
	Fixed c;
	// Fixed const b( 10 );
	// Fixed const c( 42.42f ); // dont put a coma
	// Fixed const d( b );

	a = Fixed(1234.4321f); // _fixedPoint = 316015
	b = Fixed(4.1234f); // _fixedPoint = 315904
	c = Fixed(1234); // _fixedPoint = 315904

	std::cout << "a is " << a << std::endl; // he passes by & operator <<	
	std::cout << "b is " << b << std::endl; // he passes by & operator <<
	std::cout << "c is " << c << std::endl; // he passes by & operator <<

	// std::cout << "b is " << b << std::endl; 
	// std::cout << "c is " << c << std::endl;
	// std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl; /*he doest pass by & operator << */
	std::cout << "b is " << b.toInt() << " as integer" << std::endl; /*he doest pass by & operator << */
	std::cout << "c is " << c.toInt() << " as integer" << std::endl; /*he doest pass by & operator << */
	// std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	// std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	// std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}