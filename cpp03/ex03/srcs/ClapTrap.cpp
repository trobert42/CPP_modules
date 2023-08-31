/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:31:55 by trobert           #+#    #+#             */
/*   Updated: 2023/01/16 10:37:57 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default"), _hitPoint(10), _energyPoint(10), _attkDmg(0)
{
	std::cout << "Default constructor ClapTrap called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoint(10), _energyPoint(10), _attkDmg(0)
{
	std::cout << "Parametric constructor ClapTrap called with " << name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & cpy)
{
	std::cout << "Copy constructor ClapTrap called" << std::endl; 
	*this = cpy;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor ClapTrap called with " << this->_name << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
{
	std::cout << "Assignment operation ClapTrap called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoint = rhs._hitPoint;
		this->_energyPoint = rhs._energyPoint;
		this->_attkDmg = rhs._attkDmg;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoint > 0 && this->_energyPoint > 0)
	{
		this->_energyPoint -= 1;
		std::cout
			<< "ClapTrap " << this->_name
			<< " attacks " << target
			<< ", causing " << 0
			<< " points of damage ! It's super effective *ironic*" << std::endl;
	}
	else if (this->_hitPoint == 0 && this->_energyPoint > 0)
		std::cout << "ClapTrap " << this->_name << " has no hit point" << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " has no more energy point" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoint == 0)
	{
		std::cout << this->_name << " is dead :(" << std::endl;
		return ;
	}
	if (amount > (unsigned int)this->_hitPoint)
	{
		this->_hitPoint = 0;
		std::cout << "Critical hit ! ClapTrap " << this->_name<< " has fainted" << std::endl;
	}
	else if (amount == 0)
		std::cout << "Nothing happened" << std::endl;
	else
	{
		this->_hitPoint -= amount;
		std::cout
			<< "ClapTrap " << this->_name
			<< " has lost " << amount
			<< " hit point(s), he has now " << this->_hitPoint
			<< " hit point(s)" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoint == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead, can't be healed :(" << std::endl;
		return ;
	}
	if (this->_energyPoint == 0)
		std::cout << "ClapTrap " << this->_name << " has no more energy point" << std::endl;
	else
	{
		this->_hitPoint += amount;
		this->_energyPoint -= 1;
		std::cout 
			<< "ClapTrap " << this->_name 
			<< " recovered " << amount
			<< " hit point(s), he has now " << this->_hitPoint 
			<< " hit point(s)" << std::endl;
	}
}
