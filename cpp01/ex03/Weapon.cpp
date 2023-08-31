/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:07:40 by trobert           #+#    #+#             */
/*   Updated: 2022/12/17 09:33:19 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	// std::cout << "Constructor called" << std::endl;
}

Weapon::~Weapon(void)
{
	// std::cout << "Destructor called" << std::endl;
}

std::string const & Weapon::getType(void) const
{
	return this->_type;
}

void Weapon::setType(std::string const &new_value)
{
	this->_type = new_value;
}
