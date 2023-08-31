/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:33:19 by trobert           #+#    #+#             */
/*   Updated: 2023/04/06 19:00:25 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac <= 1)
	{
		std::cerr << "Usage: ./PmergeMe [arg1] [arg_2] ... [arg_n]" << std::endl;
		return 1;
	}
	else
	{
		////////////////// MAIN TEST /////////////////
		try
		{
			PmergeMe sequence(ac, av);
			sequence.printExecutionTime();
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
		////////////////// TEST COPY /////////////////
		// try
		// {
		// 	PmergeMe original(ac, av);
		// 	original.printExecutionTime();
		// 	PmergeMe copy(original);
		// 	copy.printExecutionTime();
		// }
		// catch(const std::exception& e)
		// {
		// 	std::cerr << "Error: " << e.what() << std::endl;
		// }
	}
	return 0;
}