/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:11:08 by trobert           #+#    #+#             */
/*   Updated: 2022/12/27 17:06:12 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character(void) : _name("Default")
{
	for (int i(0); i <= 3; i++)
		this->_inventory[i] = NULL;
	// std::cout << "Default constructor for Character \"Default\" called" << std::endl;
}

Character::Character(std::string name) : _name(name) 
{
	for (int i(0); i <= 3; i++)
		this->_inventory[i] = NULL;
	// std::cout << "Parametric constructor for " << name << " called" << std::endl;
}

Character::Character(Character const & cpy)
{
	// std::cout << "Copy constructor for " << this->_name << " called" << std::endl;
	*this = cpy;
}

Character::~Character(void)
{
	// std::cout << "Destructor for character " << this->_name << " called" << std::endl;
	for (int i(0); i <= 3; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

Character & Character::operator=(Character const & rhs)
{
	// std::cout << "Assignment operator for " << this->_name << " called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		for (int i(0); i <= 3; i++)
		{
			if (rhs._inventory[i])
				this->_inventory[i] = rhs._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return *this;
}

std::string const & Character::getName(void) const
{
	return _name;
}

void	Character::equip(AMateria *m)
{
	unsigned int count = 0;

	if (!m)
	{
		std::cout << "Can't equip something null" << std::endl; 
		return ;
	}
	for (int i(0); i <= 3; i++)
	{
		if (this->_inventory[i])
			count++;
		if (this->_inventory[i] && this->_inventory[i] == m)
		{
			std::cout << "Inventory has already this materia" << std::endl;
			return ;
		}		
		if (count == 4)
			std::cout << "Inventory's full, can't add new materia" << std::endl;
	}
	for (int i(0); i <= 3; i++)
	{
		if (!this->_inventory[i] && m)
		{
			this->_inventory[i] = m;
			// std::cout << "Equip materia succeed" << std::endl;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
	{
		if (this->_inventory[idx])
		{
			this->_inventory[idx] = NULL;
			std::cout 
				<< "Unequip materia [" << idx 
				<< "] succeed" << std::endl;
		}
		else if (!this->_inventory[idx])
		{
			std::cout << "Unequip materia failed : no materia at this index" << std::endl;
			return ;
		}
	}
	else
		std::cout << "Wrong index, use between 0 and 3" << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3)
	{
		if (this->_inventory[idx])
			this->_inventory[idx]->use(target);
		else
		{
			std::cout << "Can't use skill : no materia at this index" << std::endl;
			return ;
		}
	}
	else
		std::cout << "Wrong index, use between 0 and 3" << std::endl;
}

void	Character::printInventory(void) const
{
	for (int i(0); i <= 3; i++)
	{
		std::cout 
			<< "Inventory[" << i 
			<< "] = ";
			if (this->_inventory[i])
			{
				std::cout 
					<< this->_inventory[i]->getType()
					<< " (" << this->_inventory[i]
					<< ") " << std::endl;
			}
			else
				std::cout << std::endl;
	}
}