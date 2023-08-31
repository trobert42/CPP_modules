/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:17:20 by trobert           #+#    #+#             */
/*   Updated: 2022/12/20 15:15:28 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	Point const a(1, 1);
	Point const b(2, 3);
	Point const c(3, 1);
	Point const point1(1.5f, 1.5f);
	// Point point2(2.00f, 2.84f); // is supposed to be inside the triangle

	if (bsp(a, b, c, point1) == true)
		std::cout << "The point \"point1\" is inside the triangle" << std::endl;	
	else
		std::cout << "The point \"point1\" is not inside the triangle" << std::endl << std::endl;	
	std::cout << std::endl;
	
	// if (bsp(a, b, c, point2) == true)
	// 	std::cout << "The point \"point2\" is inside the triangle" << std::endl;	
	// else
	// 	std::cout << "The point \"point2\" is not inside the triangle" << std::endl;
	
	
	return 0;
}