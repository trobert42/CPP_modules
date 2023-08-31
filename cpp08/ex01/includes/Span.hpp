/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:25:02 by trobert           #+#    #+#             */
/*   Updated: 2023/02/09 18:04:07 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
	public:
		Span(unsigned int N);
		~Span(void);

		Span(Span const & cpy);
		Span & operator=(Span const & rhs);

		unsigned int	getSize(void) const;
		void 		 	addNumber(int nbrToAdd);
		void			addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;
		void			print(void) const;

		class  TooMuchElementException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("too much element");
			}
		};

		class  DistanceNotFoundException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("coudn't find any distance between nbrs");
			}
		};

	private:
		Span(void);
	
		std::vector<int>	_span;
		unsigned int 		_size;
};

#endif