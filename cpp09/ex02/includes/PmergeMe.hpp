/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:30:50 by trobert           #+#    #+#             */
/*   Updated: 2023/04/06 19:08:25 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <algorithm>
#include <exception>
#include <ctime>

class PmergeMe
{
	public:
		PmergeMe(int ac, char **av);
		PmergeMe(PmergeMe const & cpy);
		PmergeMe & operator=(PmergeMe const & rhs);
		~PmergeMe(void);

		void				printExecutionTime(void);

		std::vector<int>	insertSort(std::vector<int> arr);
		std::vector<int>	hybridFordJohnsonSort(std::vector<int> arr);
		std::vector<int>	mergeSort(std::vector<int> left, std::vector<int> right);
	
		std::deque<int>		insertSort(std::deque<int> arr);
		std::deque<int>		hybridFordJohnsonSort(std::deque<int> arr);
		std::deque<int>		mergeSort(std::deque<int> left, std::deque<int> right);


		class  BadInputException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("invalid token found or bad input");
			}
		};

		class  NotPositiveIntegerException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("invalid number, must be only positive integer inside sequence");
			}
		};

		class  DuplicateFoundException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("invalid sequence, found duplicates");
			}
		};

		template <typename T>
		void printArray(T &arr) const
		{
			for (size_t i = 0; i < arr.size(); i++)
				std::cout << arr[i] << " ";
			std::cout << std::endl;
		}

		template <typename T>
		bool isSortedArray(T &arr) const
		{
			for (size_t i = 0; i < arr.size() - 1; i++)
			{
				if (arr[i] > arr[i + 1])
					return false;
			}
			return true;
		}


	private:
		PmergeMe(void);
		int 	isValidArg(char **av) const;
		int 	isValidNbr(char **av) const;
		bool	isNumber(std::string str) const;
		void	fillVector(char **av);
		void	filldeque(char **av);
		bool	haveDuplicates(void) const;

		size_t				_nbr_arg;
		std::vector<int>	_before_vector;
		std::vector<int>	_after_vector;
		float				_sorting_time_vector;

		std::deque<int>		_before_deque;
		std::deque<int>		_after_deque;
		float				_sorting_time_deque;
};

#endif