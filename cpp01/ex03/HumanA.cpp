/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:19:40 by trobert           #+#    #+#             */
/*   Updated: 2022/12/19 17:57:49 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &new_weapon) : _name(name), _weapon(new_weapon)
{
	// std::cout << "Constructor called" << std::endl;
}

HumanA::~HumanA(void)
{
	// std::cout << "Destructor called" << std::endl;
}

std::string	HumanA::getName(void)
{
	return this->_name;
}

void	HumanA::setName(std::string new_name)
{
	this->_name = new_name;
}

void	HumanA::attack(void) const
{
	std::cout <<
		this->_name <<
		" attacks with his/her " << this->_weapon.getType() << std::endl;
}
