/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:25:02 by trobert           #+#    #+#             */
/*   Updated: 2023/03/28 17:50:46 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <exception>

class RPN
{
	public:
		RPN(char *av);
		~RPN(void);

		RPN(RPN const & cpy);
		RPN & operator=(RPN const & rhs);

		void 	resolveExpression(void);
		size_t	getStackSize(void) const;


		class  EmptyArgException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("arg's empty");
			}
		};

		class  BadInputException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("bad input");
			}
		};

		class  InvalidTokenFoundException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("unknown token found");
			}
		};

		class  InvalidExpressionException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("invalid reverse polish expression");
			}
		};
	
		class  DivisionByZeroException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("division by zero exception");
			}
		};



	private:
		RPN(void);
		int		isValidTokens(void) const;
		void	fillStack(void);

		std::string			_expression;
		std::stack<char>	_stack;
		std::stack<int>		_resolve_stack;
		size_t				_stack_size;

};

#endif