/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:25:20 by trobert           #+#    #+#             */
/*   Updated: 2023/02/11 14:53:39 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

Span::Span(void) : _span(0), _size(0)
{
	// std::cout << "Default constructor Span called" << std::endl;
}

Span::Span(unsigned int N) : _span(std::vector<int>(0)), _size(N)
{
	// std::cout << "Parametric constructor Span called with N = " << N << std::endl;
}

Span::~Span(void)
{
	// std::cout << "Destructor Span called" << std::endl;
}

Span::Span(Span const & cpy)
{
	*this = cpy;
}

Span & Span::operator=(Span const & rhs)
{
	if (this != &rhs)
	{
		this->_span = rhs._span;
		this->_size = rhs._size;
	}
	return *this;
}

unsigned int Span::getSize(void) const
{
	return this->_size;
}

void	Span::addNumber(int nbrToAdd)
{
	if (this->_span.size() != this->_size)
		this->_span.push_back(nbrToAdd);
	else
		throw TooMuchElementException();	
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	for (std::vector<int>::iterator iter = begin; iter < end; iter++)
	{
		if (this->_span.size() >= this->_size)
			throw TooMuchElementException();
		this->_span.push_back(*iter);
	}
}

unsigned int Span::shortestSpan(void) const
{
	if (this->_span.size() <= 1)
		throw DistanceNotFoundException();
	std::vector<int> tmp = this->_span;
	std::sort(tmp.begin(), tmp.end());
	int shortest = abs(*(tmp.begin() + 1) - *tmp.begin());
	for (std::vector<int>::iterator iter = tmp.begin() + 1; iter != tmp.end() - 1; ++iter)
	{
		if (shortest > abs(*iter - *(iter - 1)))
			shortest = abs(*iter - *(iter - 1));
	}
	return shortest;
}

unsigned int Span::longestSpan(void) const
{
	if (this->_span.size() <= 1)
		throw DistanceNotFoundException();
	unsigned int min = *min_element(this->_span.begin(), this->_span.end());
	unsigned int max = *max_element(this->_span.begin(), this->_span.end());
	return (max - min);
}

void	Span::print(void) const
{
	std::cout << "Printing Span values : ";
	for (std::vector<int>::const_iterator i = this->_span.begin(); i != this->_span.end(); ++i)
   		std::cout << "[" << *i << "] ";
	std::cout << std::endl;
}
