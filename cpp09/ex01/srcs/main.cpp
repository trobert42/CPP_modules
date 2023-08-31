/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:25:36 by trobert           #+#    #+#             */
/*   Updated: 2023/03/28 17:58:27 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./RPN [reverse polish notation]" << std::endl;
		return 1;
	}

	std::cout << "------------ MAIN TEST ------------" << std::endl;
	try
	{
		RPN expression(av[1]);
		expression.resolveExpression();
	}
	catch(const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// std::cout << "------------ TEST COPY ------------" << std::endl;
	// try
	// {
	// 	RPN firstExpression(av[1]);
	// 	RPN copy(firstExpression);

	// 	std::cout << "first RPN solved : ";
	// 	firstExpression.resolveExpression();
	// 	std::cout << std::endl;

	// 	std::cout << "copy RPN solved : ";
	// 	copy.resolveExpression();
	// }
	// catch(const std::exception &e)
	// {
	// 	std::cerr << "Error: " << e.what() << std::endl;
	// }

	return 0;
}