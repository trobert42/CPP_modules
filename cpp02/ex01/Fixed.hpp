/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:07:22 by trobert           #+#    #+#             */
/*   Updated: 2022/12/20 12:14:25 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{	
	public:
		Fixed(void); // default constructor
		Fixed(int const n); // parametric constructor
		Fixed(float const n); // parametric constructor

		Fixed(Fixed const & cpy); // copy constructor
		
		~Fixed(void); // destructor

		Fixed & operator=(Fixed const & rhs); // assign operatation

		
		int 	getRawBits(void) const; // RawBits = valeur du nbr a virgule fixe
		void 	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt (void) const;


	private:
		int 				_fixedPoint; //representation du nombre donne en virgule fixe
		static int const	_fractionalBits = 8;
};

std::ostream & operator<<( std::ostream & o, Fixed const & rhs );

#endif