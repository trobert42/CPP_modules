	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:54:30 by trobert           #+#    #+#             */
/*   Updated: 2022/12/17 11:35:39 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main (void)
{
	Fixed a;

	Fixed b(a);

	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}

/*
Default constructor called // Fixed a

Copy constructor called // Fixed b(a)
Copy assignment operator called // Fixed b(a)
getRawBits member function called // Fixed b(a)

Default constructor called // Fixed c

Copy assignment operator called // c = b
getRawBits member function called // c = b

getRawBits member function called // std::cout << a.getRawBits() << std::endl;
0
getRawBits member function called // std::cout << b.getRawBits() << std::endl;
0
getRawBits member function called // std::cout << c.getRawBits() << std::endl;
0 

Destructor called // return 0
Destructor called // return 0
Destructor called // return 0
*/