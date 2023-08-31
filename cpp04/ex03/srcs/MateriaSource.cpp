/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:09:11 by trobert           #+#    #+#             */
/*   Updated: 2022/12/27 17:16:01 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i(0); i <= 3; i++)
		this->_inventory[i] = NULL;
	// std::cout << "Default constructor for MateriaSource called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & cpy)
{
	// std::cout << "Copy constructor for MateriaSource called" << std::endl;
	*this = cpy;
}

MateriaSource::~MateriaSource(void)
{
	// std::cout << "Destructor for MateriaSource called" << std::endl;
	for (int i(0); i <= 3; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs)
{
	// std::cout << "Assignment operator for MateriaSource called" << std::endl;
	if (this != &rhs)
	{
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

void	MateriaSource::learnMateria(AMateria *m)
{
	unsigned int count = 0;

	if (!m)
	{
		std::cout << "Can't learn something null" << std::endl; 
		return ;
	}
	for (int i(0); i <= 3; i++)
	{
		if (this->_inventory[i])
			count++;
		if (this->_inventory[i] && this->_inventory[i] == m)
		{
			std::cout << "Inventory of MateriaSource has already this materia" << std::endl;
			return ;
		}		
		if (count == 4)
			std::cout << "Inventory of MateriaSource is full, can't add new materia" << std::endl;
	}
	for (int i(0); i <= 3; i++)
	{
		if (!this->_inventory[i] && m)
		{
			this->_inventory[i] = m;
			// std::cout << "Equip materia for MateriaSource succeed" << std::endl;
			return ;
		}
	}	
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i(0); i <= 3; i++)
	{
		if (this->_inventory[i] && this->_inventory[i]->getType() == type)
			return this->_inventory[i]->clone();
	}
	std::cout << "You don't have this " << type << " materia or it doesn't exist" << std::endl;
	return NULL;
}

void	MateriaSource::printInventory(void) const
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