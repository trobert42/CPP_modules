/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:28:55 by trobert           #+#    #+#             */
/*   Updated: 2023/03/28 17:48:56 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: number of args != 2. Usage : ./btc [input_file]" << std::endl;
		return 1;
	}

	std::cout << "------------ MAIN TEST ------------" << std::endl;
	try
	{
		BitcoinExchange btc(av[1]);
		btc.getRatesFromDatabase();
		btc.getParsingInput();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// std::cout << "------------ TEST COPY ------------" << std::endl;
	// try 
	// {
	// 	BitcoinExchange btc(av[1]);
	// 	BitcoinExchange test(btc);
	// 	test.getRatesFromDatabase();
	// 	test.getParsingInput();
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << "Error: " << e.what() << std::endl;
	// }

	return 0;
}