 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:25:20 by trobert           #+#    #+#             */
/*   Updated: 2023/03/21 16:08:07 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

RPN::RPN(void)
{
	// std::cout << "Default constructor called for RPN" << std::endl;
}

RPN::RPN(char *av) : _expression(av)
{
	if (_expression.empty())
		throw EmptyArgException();
	if (!isValidTokens())
		throw InvalidTokenFoundException();
	fillStack(); 
	// std::cout << "Constructor called for RPN" << std::endl;
}

RPN::RPN(RPN const & cpy)
{
	// std::cout << "Copy constructor called for RPN" << std::endl;
	*this = cpy;
}

RPN & RPN::operator=(RPN const & rhs)
{
	// std::cout << "Assignment operator called for RPN" << std::endl;
	if (this != &rhs)
	{
		this->_expression = rhs._expression;
		this->_stack = rhs._stack;
		this->_resolve_stack = rhs._resolve_stack;
		this->_stack_size = rhs._stack_size;
	}
	return *this;
}

RPN::~RPN(void)
{
	// std::cout << "Destructor called for RPN" << std::endl;
}

int		RPN::isValidTokens(void) const
{
	std::string validTokens = "0123456789+-*/ ";
	for (size_t i = 0; i < _expression.size(); i++)
	{
		char c = _expression[i];
		if (validTokens.find(c) == std::string::npos)
			return 0;
	}
	return 1;
}

void	RPN::fillStack(void)
{
	size_t	count_nbrs = 0;
	size_t	count_operators = 0;

	_expression.erase(std::remove(_expression.begin(), _expression.end(), ' '), _expression.end());
	for (int i = (int) _expression.size() - 1; i >= 0; i--)
	{
		_stack.push(_expression[i]);
		if (isdigit(_expression[i]))
			count_nbrs++;
		else if (!isdigit(_expression[i]))
			count_operators++;
	}
	if (count_operators != count_nbrs - 1)
		throw InvalidExpressionException();
	if (!isdigit(_stack.top()))
		throw InvalidExpressionException();
}

size_t	RPN::getStackSize(void) const
{
	return this->_stack.size();
}

void	RPN::resolveExpression(void)
{
	_resolve_stack.push(_stack.top() - 48);
	_stack.pop();
	while ((int) _stack.size() > 0)
	{
		if (isdigit(_stack.top()))
			_resolve_stack.push(_stack.top() - 48);
		else
		{
			int carry = _resolve_stack.top();
			_resolve_stack.pop();
			if (_resolve_stack.size() == 0)
				throw InvalidExpressionException();
			if (_stack.top() == '+')
				_resolve_stack.top() += carry;
			else if(_stack.top() == '-')
				_resolve_stack.top() -= carry;
			else if(_stack.top() == '*')
				_resolve_stack.top() *= carry;
			else if (_stack.top() == '/')
			{
				if (carry == 0)
					throw DivisionByZeroException();
				_resolve_stack.top() /= carry;
			}
		}
		_stack.pop();
	}
	std::cout << _resolve_stack.top() << std::endl;
}