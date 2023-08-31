/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:17:20 by trobert           #+#    #+#             */
/*   Updated: 2022/12/20 16:45:25 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

/* a, b et c  sont les sommets du triangle
   point est le point a evaluer 
   si point sur une arrete ou sur sommet -> false */

int getDistancePoints(Point const p1, Point const p2)
{
	return sqrt(pow(p2.getXValue().getRawBits() - p1.getXValue().getRawBits(), 2) + pow(p2.getYValue().getRawBits() - p1.getYValue().getRawBits(), 2));
}

int getHeronFormula(Fixed distance1, Fixed distance2, Fixed distance3)
{
	return ((distance1.getRawBits() + distance2.getRawBits() + distance3.getRawBits()) / 2);
}

float	find_area(Point const a, Point const b, Point const c)
{
	Fixed		area;
	Fixed		s;
	Fixed		distanceAB;
	Fixed		distanceAC;
	Fixed		distanceBC;

	distanceAB.setRawBits(getDistancePoints(a, b));
	distanceAC.setRawBits(getDistancePoints(a, c));
	distanceBC.setRawBits(getDistancePoints(b, c));

	std::cout << "AB = " << distanceAB << ", AC = " << distanceAC << ", BC = " << distanceBC << std::endl;
	s.setRawBits(getHeronFormula(distanceAB, distanceAC, distanceBC));
	std::cout << "s = " << s << std::endl;

	float real_area = sqrt(s.toFloat() * (s.toFloat() - distanceAB.toFloat()) * (s.toFloat() - distanceBC.toFloat()) * (s.toFloat() - distanceAC.toFloat()));
	return real_area;
}
   

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float bigArea = find_area(a, b, c);
	float abp_area = find_area(a, b, point);
	float apc_area = find_area(a, point, c); 
	float bcp_area = find_area(b, c, point); 

	std::cout << "apb_area = " << abp_area << std::endl;
	std::cout << "apc_area = " << apc_area << std::endl;
	std::cout << "bcp_area = " << bcp_area << std::endl;
	float sum = (abp_area + apc_area + bcp_area); 
	std::cout
		<< "bigAreaValue = " << bigArea
		<< " and sum of small areas = " << sum << std::endl;
	if (bigArea != sum || abp_area == 0 || apc_area == 0 || bcp_area == 0)
		return false ;
	else
		return true ;
	return true ;
}