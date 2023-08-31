/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:45:32 by trobert           #+#    #+#             */
/*   Updated: 2023/01/16 10:38:31 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->_name = "Default";
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attkDmg = 30;
	std::cout << "Default constructor FragTrap called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_name = name;
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attkDmg = 30;
	std::cout << "Parametric constructor FragTrap called with " << this->_name << std::endl;
}

FragTrap::FragTrap(FragTrap const & cpy) : ClapTrap(cpy)
{
	std::cout << "Copy constructor FragTrap called" << std::endl; 
	*this = cpy;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor FragTrap called with " << this->_name << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
{
	std::cout << "Assignment operation FragTrap called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoint = rhs._hitPoint;
		this->_energyPoint = rhs._hitPoint;
		this->_attkDmg = rhs._attkDmg;
	}
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	if (this->_hitPoint > 0 && this->_energyPoint > 0)
	{
		this->_energyPoint -= 1;
		std::cout
			<< "FragTrap " << this->_name
			<< " says: up top boys!" << std::endl;
	}
	else if (this->_hitPoint == 0 && this->_energyPoint > 0)
		std::cout << "FragTrap " << this->_name << " is dead, can't high five :(" << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " has no more energy point" << std::endl;
}