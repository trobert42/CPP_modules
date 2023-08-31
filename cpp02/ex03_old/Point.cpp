/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:31:21 by trobert           #+#    #+#             */
/*   Updated: 2022/11/19 16:34:07 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Point::Point( float const new_x, float const new_y ) : _x(new_x), _y(new_y)
{
	// std::cout << "Parametric constructor called" << std::endl;
}

Point::Point(Point const & cpy) : _x(cpy.getXValue()), _y(cpy.getYValue())
{
	// std::cout << "Copy constructor called" << std::endl;
}

Point::~Point( void )
{
	// std::cout << "Destructor called" << std::endl;
}

Point & Point::operator=( Point const & ) //can't modify any const value, so just return *this
{
	return *this;
}

Fixed Point::getXValue( void ) const
{
	return this->_x;
}

Fixed Point::getYValue( void ) const
{
	return this->_y;
}