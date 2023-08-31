/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:17:36 by trobert           #+#    #+#             */
/*   Updated: 2022/11/18 17:45:03 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ): _fixedPoint(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int const n )
{
	// std::cout << "Int constructor called" << std::endl;
	this->_fixedPoint = n * pow(2, this->_fractionalBits);
}

Fixed::Fixed( float const n )
{
	// std::cout << "Float constructor called" << std::endl;
	this->_fixedPoint = (int) roundf(n * pow(2, this->_fractionalBits));
}

Fixed::Fixed( Fixed const & cpy ) //copy constructor
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

Fixed::~Fixed( void )
{
	// std::cout << "Destructor called" << std::endl;
}

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

Fixed & Fixed::operator=( Fixed const & rhs)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPoint = rhs.getRawBits(); 
	return *this;
}

bool Fixed::operator==( Fixed const & rhs)
{
	if (this->_fixedPoint == rhs.getRawBits())
		return true;
	return false;
}

bool Fixed::operator!=( Fixed const & rhs)
{
	if (this->_fixedPoint != rhs.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>( Fixed const & rhs)
{
	if (this->_fixedPoint > rhs.getRawBits())
		return true;
	return false;
}
bool Fixed::operator>=( Fixed const & rhs)
{
	if (this->_fixedPoint >= rhs.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<( Fixed const & rhs)
{
	if (this->_fixedPoint < rhs.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<=( Fixed const & rhs)
{
	if (this->_fixedPoint <= rhs.getRawBits())
		return true;
	return false;
}

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

Fixed	Fixed::operator+( Fixed const & rhs ) const
{
	// std::cout << "Addition operator called" << std::endl;
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-( Fixed const & rhs ) const
{
	// std::cout << "Substraction operator called" << std::endl;
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*( Fixed const & rhs ) const
{
	// std::cout << "Multiplication operator called" << std::endl;
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/( Fixed const & rhs ) const
{
	// std::cout << "Division operator called" << std::endl;
	return Fixed(this->toFloat() / rhs.toFloat());
}

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

Fixed & Fixed::operator++( void )
{
	this->_fixedPoint++;
	return *this;
}

Fixed Fixed::operator++( int )
{
	Fixed newFixed = *this;
	++*this;
	return newFixed;
}

Fixed & Fixed::operator--( void )
{
	this->_fixedPoint--;
	return *this;
}

Fixed Fixed::operator--( int )
{
	Fixed newFixed = *this;
	--*this;
	return newFixed;
}
///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

float Fixed::min(Fixed const & lhs, Fixed const & rhs)
{
	if (lhs.toFloat() <= rhs.toFloat())
		return (rhs.toFloat());
	else
		return (lhs.toFloat());
}

float Fixed::min(Fixed & lhs, Fixed & rhs)
{
	if (lhs.toFloat() <= rhs.toFloat())
		return (rhs.toFloat());
	else
		return (lhs.toFloat());
}

float Fixed::max(Fixed const & lhs, Fixed const & rhs)
{
	if (rhs.toFloat() >= lhs.toFloat())
		return (rhs.toFloat());
	else
		return (lhs.toFloat());
}

float Fixed::max(Fixed & lhs, Fixed & rhs)
{
	if (rhs.toFloat() >= lhs.toFloat())
		return (rhs.toFloat());
	else
		return (lhs.toFloat());
}

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

int	Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return _fixedPoint;
}

void	Fixed::setRawBits ( int const Raw )
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPoint = Raw;
}

int 	Fixed::toInt( void ) const
{
	return this->_fixedPoint / pow(2, this->_fractionalBits);
}

float	Fixed::toFloat( void ) const
{
	return  ((float) this->_fixedPoint / pow(2, this->_fractionalBits));
}

std::ostream & operator<<( std::ostream & o, Fixed const & rhs )
{
	o << rhs.toFloat();
	return o;
}