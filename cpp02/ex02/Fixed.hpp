/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:17:30 by trobert           #+#    #+#             */
/*   Updated: 2022/12/20 11:38:15 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{	
	public:
		Fixed(void);
		Fixed(int const n);
		Fixed(float const n);
		
		Fixed(Fixed const & cpy);
		
		~Fixed(void); 

		/*operateurs de comparaisons*/
		Fixed & operator=(Fixed const & rhs);
		bool operator==(Fixed const & rhs); // bool ?
		bool operator!=(Fixed const & rhs);
		bool operator>(Fixed const & rhs);
		bool operator>=(Fixed const & rhs);
		bool operator<(Fixed const & rhs);
		bool operator<=(Fixed const & rhs);

		/*operateurs de arithmetiques*/
		Fixed operator+(Fixed const & rhs) const; 
		Fixed operator-(Fixed const & rhs) const;
		Fixed operator*(Fixed const & rhs) const;
		Fixed operator/(Fixed const & rhs) const;

		/*operateurs d'incrementations et de decrementations*/
		Fixed & operator++(void); // pre-increment
		Fixed operator++(int); // post-increment
		Fixed & operator--(void);
		Fixed operator--(int);
		/*Les 4 opérateurs d’incrémentation et de décrémentation (pré-incrémentation et
		post-incrémentation, pré-décrémentation et post-décrémentation) qui diminueront
		la valeur du nombre à virgule fixe d’unité ϵ tel que 1 + ϵ > 1.*/

		static float	min(Fixed & lhs, Fixed & rhs); // float ?
		static float	min(Fixed const & lhs, Fixed const & rhs); // 	const ? 
		static float	max(Fixed & lhs, Fixed & rhs);
		static float	max(Fixed const & lhs, Fixed const & rhs);

		int 	getRawBits(void) const;
		void 	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt (void) const;


	private:
		int 				_fixedPoint;
		static int const	_fractionalBits = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif