/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:11:03 by trobert           #+#    #+#             */
/*   Updated: 2022/12/20 14:41:16 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
	Virgule fixe: maniere de representer un nombre. Dispose d'un
	n fractionnalBits reserves pour la partie fractionnaire et d'un autre
	nombre representant la section entiere.

	Virgule flottante: n'a pas de nombre specifique de chiffres reserves pour 
	les deux parties (entiere et fractionnaire).
			 (signe) × (mantisse) × (base**exposant)
<=>	1234.4321 = (+1) x (12344321) x (10**-4)

	Il faut convertir un entier n en virgule fixe (entier). 
	Bitshifter 8 bits vers la gauche car le sujet specifie que la partie fractionnaire est de 8. 
	int n = 1234,00000000 <=> 10011010010,00000000 (binaire) ->
					(binaire) 1001101001000000000, <=> _fixedPoint = 315904 
*/

Fixed::Fixed(void): _fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const n)
{
	/*convertir un int n en int virgule fixe*/
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPoint = n * pow(2, this->_fractionalBits);
}

Fixed::Fixed(float const n)
{
	/*convertir un float n en int virgule fixe*/
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPoint = (int) roundf(n * pow(2, this->_fractionalBits));
	/* Round x to the nearest whole number */
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const & cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPoint = rhs.getRawBits(); 
	return *this;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedPoint;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPoint = raw;
}

int 	Fixed::toInt(void) const
{
	/*convertir valeur en virgule fixe en nombre entier*/
	// std::cout << "int fixedPoint before bitshifting :" << (this->_fixedPoint / pow(2, 8)) << std::endl;
	return this->_fixedPoint / pow(2, this->_fractionalBits);
}

float	Fixed::toFloat(void) const
{
	/*convertir valeur en virgule fixe en virgule flottante*/
	// std::cout << "float fixedPoint before bitshifting :" << (this->_fixedPoint / pow(2, 8)) << std::endl;
	return  ((float) this->_fixedPoint / pow(2, this->_fractionalBits));
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	/*cette fonction n'est appele que lorsque on met l'instance en parametre
	il faut affichier le nombre a virgule flottant du virgule fixe*/
	o << rhs.toFloat() << " : virgule flottant";
	return o;
}
