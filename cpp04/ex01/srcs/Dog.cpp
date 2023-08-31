/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:53:11 by trobert           #+#    #+#             */
/*   Updated: 2023/01/16 16:03:16 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Default Dog constructor called" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(std::string name) : Animal("Dog"), _name(name)
{
	std::cout << "Default Dog constructor called" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(Dog const & cpy) : Animal(cpy)
{
	std::cout << "Copy Dog constructor called" << std::endl;
	this->_brain = new Brain();
	*this = cpy;
}

Dog::~Dog(void)
{
	std::cout << "Destructor Dog called" << std::endl;
	delete this->_brain;
}

Dog & Dog::operator=(Dog const & rhs)
{
	std::cout << "Assignment function Dog called" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.getType();
		*this->_brain = *rhs._brain; //deep copy
		// this->_brain = rhs._brain; // shallow copy
	}
	return *this;
}

void	Dog::setName(std::string name)
{
	this->_name = name;
}

void	Dog::makeSound(void) const
{
	std::cout << type << ": wouafwouaf" << std::endl;
}

Brain	*Dog::getAddrBrain(void) const
{
	return _brain;
}

void	Dog::printIdea(int i) const
{
	if (i >= 0 && i < 100)
		std::cout << this->_name <<" idea[" << i << "] is : " << this->_brain->_ideas[i]<< std::endl;
	else
		std::cout << "Error on index" << std::endl;
}
void	Dog::setIdea(int i, std::string new_idea)
{
	if (i >= 0 && i < 100)
		this->_brain->_ideas[i] = new_idea;
	else
		std::cout << "Error on index" << std::endl;
}