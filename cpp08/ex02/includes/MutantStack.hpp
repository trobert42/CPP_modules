/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:25:02 by trobert           #+#    #+#             */
/*   Updated: 2023/02/11 14:25:21 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void) {};
		MutantStack(const MutantStack<T>& src) { *this = src; };
		~MutantStack(void) {};
		MutantStack<T> & operator=(MutantStack<T> const & rhs)
		{
			this->c = rhs.c;
			return *this;
		};

		typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

		iterator begin(void) { return this->c.begin(); };
		iterator end(void) { return this->c.end(); };
		iterator rbegin(void) { return this->c.rbegin(); };
		iterator rend(void) { return this->c.rend(); };
};

#endif