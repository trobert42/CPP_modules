/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:59:42 by trobert           #+#    #+#             */
/*   Updated: 2023/01/16 14:06:55 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/ClapTrap.hpp"

int main(void)
{
	ClapTrap character1("Pichu");
	ClapTrap character3("Toudoudou");
	ClapTrap character2(character3);
	std::cout << std::endl;

	character1.attack("Toudoudou"); //atk = 0, this has no sense
	character2.takeDamage(9); //took damages but still alive
	std::cout << std::endl;
	
	character2.attack("Pichu");
	character1.takeDamage(30000); // more than he has life
	std::cout << std::endl;
	
	character1.beRepaired(10); // but pichu's dead
	std::cout << std::endl;

	for (int i(1); i < 10; i++)
		character2.beRepaired(1);
	character2.beRepaired(1); // no more nrj point
	character2.attack("a rock"); // no more nrj point

	
	std::cout << std::endl;

	return 0;
}