/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:32:46 by trobert           #+#    #+#             */
/*   Updated: 2023/04/17 14:45:40 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	// std::cout << "Default constructor called for PmergeMe" << std::endl;
}

PmergeMe::PmergeMe(int ac, char **av) : _nbr_arg(ac), _sorting_time_vector(0), _sorting_time_deque(0)
{
	if (!isValidArg(av))
		throw BadInputException();
	if (!isValidNbr(av))
		throw NotPositiveIntegerException();
	fillVector(av);
	filldeque(av);
	// std::cout << "Constructor called for PmergeMe" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const & cpy)
{
	// std::cout << "Copy constructor called for PmergeMe" << std::endl;
	*this = cpy;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs)
{
	// std::cout << "Assignment operator called for PmergeMe" << std::endl;
	 if (this != &rhs)
	 {
		 this->_nbr_arg = rhs._nbr_arg;
		 this->_before_vector = rhs._before_vector;
		 this->_after_vector = rhs._after_vector;
		 this->_before_deque = rhs._before_deque;
		 this->_after_deque = rhs._after_deque;
		 this->_sorting_time_vector = rhs._sorting_time_vector;
		 this->_sorting_time_deque = rhs._sorting_time_deque;
	 }
	 return *this;
}

PmergeMe::~PmergeMe(void)
{
	// std::cout << "Destructor called for PmergeMe" << std::endl;
}

bool	PmergeMe::isNumber(std::string str) const
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[0] == '+' || str[0] == '-')
			continue;
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

int PmergeMe::isValidArg(char **av) const
{
	for (size_t i = 1; i < _nbr_arg; i++)
	{
		std::string tmp = av[i];
		if (tmp.empty() || isNumber(tmp) == false)
			return 0;
	}
	return 1;
}

int PmergeMe::isValidNbr(char **av) const
{
	for (size_t i = 1; i < _nbr_arg; i++)
	{
		std::string tmp = av[i];
		if (std::strtod(tmp.c_str(), NULL) < 0 || std::strtod(tmp.c_str(), NULL) > 2147483647)
			return 0;
	}
	return 1;
}

bool	PmergeMe::haveDuplicates(void) const
{
	if (_nbr_arg <= 1)
		return false;
	size_t i = 0;
	while (i < _before_vector.size())
	{
		size_t j = i + 1;
		while (j < _before_vector.size())
		{
			if (_before_vector[i] == _before_vector[j])
				return true;
			j++;
		}
		i++;
	}
	return false;
}

void	PmergeMe::fillVector(char **av)
{
	for (size_t i = 1; i < _nbr_arg; i++)
	{
		std::string tmp = av[i];
		_before_vector.push_back(std::strtod(tmp.c_str(), NULL));
		_after_vector.push_back(std::strtod(tmp.c_str(), NULL));
	}
	if (haveDuplicates() == true)
		throw DuplicateFoundException();
}

void	PmergeMe::filldeque(char **av)
{
	for (size_t i = 1; i < _nbr_arg; i++)
	{
		std::string tmp = av[i];
		_before_deque.push_back(std::strtod(tmp.c_str(), NULL));
		_after_deque.push_back(std::strtod(tmp.c_str(), NULL));
	}
}

void	PmergeMe::printExecutionTime(void)
{
	std::cout << "Before:  ";
	_after_vector = _before_vector;
	_after_deque = _before_deque;
	printArray(_before_vector);

	if (isSortedArray(_before_vector) == false)
	{
		const clock_t begin_time_vector = clock();
		_after_vector = hybridFordJohnsonSort(_before_vector);
		const clock_t end_time_vector = clock();
		_sorting_time_vector = (float(end_time_vector - begin_time_vector) / CLOCKS_PER_SEC) * 1000000;

		const clock_t begin_time_deque = clock();
		_after_deque = hybridFordJohnsonSort(_before_deque);
		const clock_t end_time_deque = clock();
		_sorting_time_deque = (float(end_time_deque - begin_time_deque) / CLOCKS_PER_SEC) * 1000000;
	}

	std::cout << "After:   ";
	printArray(_after_vector);
	std::cout << "Time to process a range of " << _after_vector.size() << " elements with std::vector : " << _sorting_time_vector << " us" << std::endl;
	std::cout << "Time to process a range of " << _after_deque.size() << " elements with std::deque : " << _sorting_time_deque << " us" << std::endl;
}
