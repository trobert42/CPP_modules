/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:06:54 by trobert           #+#    #+#             */
/*   Updated: 2022/12/21 18:51:12 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

/*
	Constructor HA takes a weapon as a parameter because HA has always a weapon
	Constructor HB doesn't take a weapon at first, but can have a weapon later
*/

int main(void) 
{
	Weapon test = Weapon(NULL); 
	HumanA bob("Bob Marley", test);
	bob.attack();

	Weapon weapon1 = Weapon("crude spiked club");
	HumanB jim("Jimmy Hendrix");
	jim.attack(); //no weapon
	jim.setWeapon(weapon1); //crude spiked club
	jim.attack();
	weapon1.setType("electric guitar");
	jim.attack();
	return 0;
}