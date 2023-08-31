
: member 'size' found in multiple base classes of different types/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:57:24 by trobert           #+#    #+#             */
/*   Updated: 2023/01/16 11:16:43 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	this->_name = "Default";
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->_hitPoint = FragTrap::_hitPoint;
	this->_energyPoint = ScavTrap::_energyPoint;
	this->_attkDmg = FragTrap::_attkDmg;
	std::cout << "Default constructor DiamondTrap called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	this->_name = name;
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->_hitPoint = FragTrap::_hitPoint;
	this->_energyPoint = ScavTrap::_energyPoint;
	this->_attkDmg = FragTrap::_attkDmg;
	std::cout << "Parametric constructor DiamondTrap called with " << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & cpy) : ClapTrap(cpy), ScavTrap(cpy), FragTrap(cpy)
{
	std::cout << "Copy constructor DiamondTrap called" << std::endl; 
	*this = cpy;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Destructor DiamondTrap called with " << this->_name << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & rhs)
{
	std::cout << "Assignment operation DiamondTrap called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoint = rhs._hitPoint;
		this->_energyPoint = rhs._hitPoint;
		this->_attkDmg = rhs._attkDmg;
	}
	return *this;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) const
{
	std::cout
		<< "DiamondTrap " << this->_name 
		<< ": who am i ?" << std::endl
		<< "Name : " << this->_name << std::endl
		<< "ClapTrap name : " << ClapTrap::_name << std::endl;
}

void 	DiamondTrap::printInfoChar(void) const
{
	std::cout
		<< "DiamondTrap name : " << this->_name << std::endl
		<< "ClapTrap::name : " << ClapTrap::_name << std::endl
		<< "Hit point : " << FragTrap::_hitPoint << std::endl
		<< "Energy point : " << ScavTrap::_energyPoint << std::endl
		<< "Attack Damage : " << FragTrap::_attkDmg << std::endl;
}
