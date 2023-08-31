/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:28:55 by trobert           #+#    #+#             */
/*   Updated: 2023/02/09 13:34:01 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/whatever.hpp"
#include <iostream>
#include <string>

int main(void)
{
	std::cout << "------ TRYING WITH INT AND EXPLICIT INSTANCIATION ------" << std::endl;
	int a = 3, b = 5;
	std::cout << "Before swap a: " << a << " and b: " << b << std::endl;
	swap<int>(a, b);
	std::cout << "After swap a: " << a << " and b: " << b << std::endl;
	std::cout << "The min between a and b is " << min<int>(a, b) << std::endl;
	std::cout << "The max between a and b is " << max<int>(a, b) << std::endl << std::endl;

	std::cout << "------ TRYING WITH FLOAT AND IMPLICIT INSTANCIATION ------" << std::endl;
	double c = 3.141, d = 1.618;
	std::cout << "Before swap c: " << c << " and d: " << d << std::endl;
	swap(c, d);
	std::cout << "After swap c: " << c << " and d: " << d << std::endl;
	std::cout << "The min between c and d is " << min(c, d) << std::endl;
	std::cout << "The max between c and d is " << max(c, d) << std::endl << std::endl;


	std::cout << "------ TRYING WITH CHAR IMPLICIT INSTANCIATION ------" << std::endl;
	char value1 = 'k', value2 = 'y';
	std::cout << "Before swap value1: " << value1 << " and value2: " << value2 << std::endl;
	swap(value1, value2);
	std::cout << "After swap value1: " << value1 << " and value2: " << value2 << std::endl;
	std::cout << "The min between value1 and value2 is " << min(value1, value2) << std::endl;
	std::cout << "The max between value1 and value2 is " << max(value1, value2) << std::endl << std::endl;


	std::cout << "------ TRYING WITH STRING IMPLICIT INSTANCIATION ------" << std::endl;
	std::string str1 = "beaucoup";
	std::string str2 = "peu";
	std::cout << "Before swap str1: " << str1 << " and str2: " << str2 << std::endl;
	swap(str1, str2);
	std::cout << "After swap str1: " << str1 << " and str2: " << str2 << std::endl;
	std::cout << "The min between str1 and str2 is " << ::min(str1, str2) << std::endl;
	std::cout << "The max between str1 and str2 is " << ::max(str1, str2) << std::endl << std::endl;


	std::cout << "------ TRYING WITH CONST VALUE ------" << std::endl;
	// const int nbr1 = 42, nbr2 = 24;
	int nbr3 = 42, nbr4 = 24;
	// std::cout << "min(nbr1, nbr2)++ = " << ++min(nbr1, nbr2) << std::endl;
	std::cout << "++min(nbr3, nbr4) = " << ++min(nbr3, nbr4) << std::endl;


	// std::cout << "------ GIVEN MAIN ------" << std::endl;
	// int a = 2;
	// int b = 3;
	// ::swap( a, b );
	// std::cout << "a = " << a << ", b = " << b << std::endl;
	// std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	// std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	// std::string c = "chaine1";
	// std::string d = "chaine2";
	// ::swap(c, d);
	// std::cout << "c = " << c << ", d = " << d << std::endl;
	// std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	// std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return 0;
}