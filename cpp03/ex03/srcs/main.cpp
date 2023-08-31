/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:32:41 by trobert           #+#    #+#             */
/*   Updated: 2023/01/16 10:58:17 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/DiamondTrap.hpp"

int main(void)	
{
	DiamondTrap character1("Metamorphe");
	std::cout << std::endl;

	character1.whoAmI();
	std::cout << std::endl;

	character1.highFivesGuys();
	character1.guardGate();
	character1.beRepaired(1);
	character1.attack("the wall");
	character1.printInfoChar();
	std::cout << std::endl;

	DiamondTrap character2("Morpheo");
	std::cout << std::endl;

	character2.attack("Metamorphe");
	character1.takeDamage(30);
	std::cout << std::endl;

	character2.printInfoChar();
	std::cout << std::endl;

	character1.printInfoChar();
	std::cout << std::endl;

	return 0;
}