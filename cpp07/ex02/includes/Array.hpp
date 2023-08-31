/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:00:27 by trobert           #+#    #+#             */
/*   Updated: 2023/02/09 13:18:02 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <cstring>

template <typename T>
class Array
{
	public:
		Array(void) : _array(NULL), _size(0) {};
		Array(unsigned int n) : _array(new T[n]), _size(n) { memset(this->_array, 0, sizeof(T) * n); };
		
		Array(Array const & cpy) : _array(NULL), _size(0) {	*this = cpy; };

		~Array(void) { delete [] this->_array; };

		Array & operator=(Array const & rhs)
		{
			if (this == &rhs)
				return *this;
			if (this->_size != rhs._size)
				delete [] this->_array;
			this->_array = NULL;
			if (rhs._size > 0)
			{
				this->_array = new T[rhs._size];
				this->_size = rhs._size;
				for (unsigned int i(0); i < this->_size; i++)
					this->_array[i] = rhs._array[i];
			}
			return *this;
		};
	
		T & operator[](unsigned int index)
		{
			if (index >= this->_size)
				throw InvalidIndexException();
			return this->_array[index];
		};

		T const & operator[](unsigned int index) const
		{
			if (index >= this->_size)
				throw InvalidIndexException();
			return this->_array[index];
		};

		unsigned int size(void) const {	return this->_size;	};
		
		class InvalidIndexException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return("invalid index");
				}
		};

	private:
		T *_array;
		unsigned int _size;
};

#endif