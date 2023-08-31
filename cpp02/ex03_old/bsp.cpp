/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:17:20 by trobert           #+#    #+#             */
/*   Updated: 2022/11/20 10:45:26 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

/* a, b et c  sont les sommets du triangle
   point est le point a evaluer 
   si point sur une arrete ou sur sommet -> false */

Fixed	getSideSign(Point const a, Point const b, Point const p)
{
	Fixed	x1(a.getXValue());
	Fixed	x2(b.getXValue());
	Fixed	xp(p.getXValue());
	Fixed	y1(a.getYValue());
	Fixed	y2(b.getYValue());
	Fixed	yp(p.getYValue());

	return (y2 - y1) * (xp - x1) + ((x2 * -1) + x1) * (yp - y1);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed sideAB = getSideSign(a, b, point);
	Fixed sideBC = getSideSign(b, c, point);
	Fixed sideCA = getSideSign(c, b, point); 

	if (sideAB > 0 && sideBC > 0 && sideCA > 0)
		return true;
	else if (sideAB < 0 && sideBC < 0 && sideCA < 0)
		return true;
	else
		return false;
}