/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:26:26 by trobert           #+#    #+#             */
/*   Updated: 2022/12/17 10:57:24 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main (int ac, char **av)
{
	PhoneBook 		repertoire;
	std::string		input;

	(void)av;
	if (ac != 1)
		return (std::cout << "Error : no arg required" << std::endl, 0);
	while (true && std::cin)
	{ 
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "Enter a command (ADD, SEARCH or EXIT)" << std::endl;
		std::getline(std::cin, input);
		if (!std::cin)
			break ;
		if (input == "ADD")
			repertoire.addCommand();
		else if (input == "SEARCH")
			repertoire.searchCommand();
		else if (input == "EXIT")
			break ;
		input.erase();
	}
	return (0);	
}
