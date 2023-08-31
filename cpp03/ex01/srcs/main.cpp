/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:32:41 by trobert           #+#    #+#             */
/*   Updated: 2023/01/16 09:54:52 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int main(void)
{
	ScavTrap character1("Simularbre");
	ClapTrap character2("Magikarp");
	std::cout << std::endl;
	
	character1.guardGate();
	character2.attack("Simularbre");
	character1.takeDamage(0);
	std::cout << std::endl;

	character1.attack("Magikarp");
	character2.takeDamage(20);
	character2.beRepaired(1);
	std::cout << std::endl;

	// for (int i(1); i < 50; i++)
	// 	character1.beRepaired(1);
	// character1.beRepaired(1); // no more nrj point
	// character1.attack("a rock"); // no more nrj point
	// std::cout << std::endl;

	ScavTrap character3("Miaouss");
	character1.attack("Miaouss");
	character1.attack("Miaouss");
	character1.attack("Miaouss");
	character1.attack("Miaouss");
	character1.attack("Miaouss");
	character3.takeDamage(100);
	std::cout << std::endl;

	return 0;
}