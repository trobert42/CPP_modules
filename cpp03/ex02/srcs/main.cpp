/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:32:41 by trobert           #+#    #+#             */
/*   Updated: 2023/01/16 10:35:26 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

int main(void)
{
	FragTrap character1("Carapuce");
	ScavTrap character2("Salameche");
	ClapTrap character3("Bulbizarre");
	std::cout << std::endl;

	character1.highFivesGuys();
	character2.guardGate();
	character3.beRepaired(1);
	std::cout << std::endl;
	
	return 0;
}