/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:37:26 by trobert           #+#    #+#             */
/*   Updated: 2023/01/18 13:22:33 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>
#include <cstdlib>
#include <climits>

class Convert
{
	public:
		Convert(void);
		
		Convert(std::string v);

		Convert(Convert const & cpy);	

		~Convert(void);

		Convert & operator=(Convert const & rhs);

		int		parseLitteral(void);

		void	getValueType(void);
		void	castFromInt(void);
		void	castFromChar(void);
		void	castFromFloat(void);
		void	castFromDouble(void);
	
		void	printCast(void);

		class NotPrintableException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Non displayable");
				}
		};

		class ImpossibleConvertionException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("impossible");
				}
		};

		class ScalarNotManagedException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("impossible");
				}
		};

	
	private:
		std::string _value;

		std::string	_specialCase;

		bool		_isOverflow;
		bool		_isAscii;
	
		char		_char;
		int			_int;
		float		_float;
		double		_double;

		static const int 	SIZE_TAB = 6;
};

#endif