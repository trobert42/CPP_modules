/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:33:58 by trobert           #+#    #+#             */
/*   Updated: 2023/01/16 10:21:23 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void)
{
	this->_name = "Default";
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attkDmg = 20;
	std::cout << "Default constructor ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_name = name;
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attkDmg = 20;
	std::cout << "Parametric constructor ScavTrap called with " << this->_name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & cpy) : ClapTrap(cpy)
{
	std::cout << "Copy constructor ScavTrap called" << std::endl; 
	*this = cpy;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor ScavTrap called with " << this->_name << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
{
	std::cout << "Assignment operation ScavTrap called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoint = rhs._hitPoint;
		this->_energyPoint = rhs._hitPoint;
		this->_attkDmg = rhs._attkDmg;
	}
	return *this;
}

void	ScavTrap::guardGate(void)
{
	if (this->_hitPoint > 0 && this->_energyPoint > 0)
	{
		this->_energyPoint -= 1;
		std::cout
		<< "ScavTrap " << this->_name
		<< " has activated his Guardgate mode!" << std::endl;
	}
	else if (this->_hitPoint == 0 && this->_energyPoint > 0)
		std::cout << "SlavTrap " << this->_name << " is dead, can't guard anything :(" << std::endl;
	else
		std::cout << "SlavTrap " << this->_name << " has no more energy point" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoint > 0 && this->_energyPoint > 0)
	{
		this->_energyPoint -= 1;
		std::cout
			<< "SlavTrap " << this->_name
			<< " attacks " << target
			<< ", causing " << this->_attkDmg
			<< " points of damage ! Amazing :o" << std::endl;
	}
	else if (this->_hitPoint == 0 && this->_energyPoint > 0)
		std::cout << "SlavTrap " << this->_name << " is dead, can't attack :(" << std::endl;
	else
		std::cout << "SlavTrap " << this->_name << " has no more energy point" << std::endl;
}