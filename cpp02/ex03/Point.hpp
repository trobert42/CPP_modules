/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:35:34 by trobert           #+#    #+#             */
/*   Updated: 2022/12/20 14:56:00 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point 
{	
	public:
		Point(void);
		
		Point(float const new_x, float const new_y);
		
		Point(Point const & cpy);
		
		~Point(void);
	
		Point & operator=(Point const & rhs);
		
		Fixed	getXValue(void) const ;
		Fixed	getYValue(void) const ;

	
	private:
		Fixed const _x;
		Fixed const _y;
};

#endif