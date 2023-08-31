/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:48:22 by trobert           #+#    #+#             */
/*   Updated: 2022/12/20 10:58:08 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
	// std::cout << "Constructor called" << std::endl;
}

HumanB::~HumanB(void)
{
	// std::cout << "Destructor called" << std::endl;
}

std::string	HumanB::getName(void)
{
	return this->_name;
}

void	HumanB::setName(std::string new_name)
{
	this->_name = new_name;
}

void	HumanB::setWeapon(Weapon &new_weapon)
{
	this->_weapon = &new_weapon;
}

void	HumanB::attack(void) const
{
	if (this->_weapon)
	{
		std::cout << this->_name <<
			" attacks with his/her " << this->_weapon->getType() << std::endl;	
	}
	else
	{
		std::cout << this->_name << " has no weapon" << std::endl;	
	}
}