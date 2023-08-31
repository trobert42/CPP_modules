/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:25:20 by trobert           #+#    #+#             */
/*   Updated: 2023/03/21 15:30:57 by trobert          ###   ########.fr       */
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
	if (!isValidLine())
		throw BadInputException();
	fillStack();
	// std::cout << "stack size = " << _stack.size() << std::endl;
	if (_stack.size() % 2 == 0)
		throw InvalidExpressionException();
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

	}
	return *this;
}

RPN::~RPN(void)
{
	// std::cout << "Destructor called for RPN" << std::endl;
}

int		RPN::isValidTokens(void)
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

int		RPN::isValidLine(void)
{
	if (_expression.size() % 2 == 0)
		return 0;
	for (size_t i = 0; i < _expression.size(); i++)
	{
		if (i % 2 != 0 && _expression[i] != ' ')
			return 0;
	}
	return 1;
}

void	RPN::fillStack(void)
{
	size_t	count_nbrs = 0;
	size_t	count_operators = 0;
	// std::cout << "expression size = " << _expression.size() << std::endl;
	for (int i = (int) _expression.size(); --i >= 0; i--)
	{
		// std::cout << "i = " << i << std::endl;
		if (i % 2 == 0)
			_stack.push(_expression[i]);
		if (isdigit(_expression[i]))
			count_nbrs++;
		else
			count_operators++;
	}
	_stack_size = _stack.size();
	if (count_operators != count_nbrs - 1)
		throw InvalidExpressionException();
}

void	RPN::printStack(void)
{
	// std::cout << "stack size = " << _stack.size() << std::endl;
	size_t size = _stack.size();
	for (size_t i = 0; i < size; i++)
	{
		std::cout << "stack[" << i << "] = " << _stack.top() << std::endl;
		_stack.pop();
	}
}

size_t	RPN::getStackSize(void) const
{
	return this->_stack.size();
}

void	RPN::resolveExpression(void)
{
	if (!isdigit(_stack.top()))
		throw InvalidExpressionException();
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

/*
	things to check :

	things to change :
		- forest of if/else if
		- assignment operator
		- delete all the useless std::cout
*/