/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:53:29 by trobert           #+#    #+#             */
/*   Updated: 2023/01/16 13:01:43 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Default Cat constructor called" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(std::string name) : Animal("Cat"), _name(name)
{
	std::cout << "Default Cat constructor called" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(Cat const & cpy) : Animal(cpy)
{
	std::cout << "Copy Cat constructor called" << std::endl;
	this->_brain = new Brain();
	*this = cpy;
}

Cat::~Cat(void)
{
	std::cout << "Destructor Cat called" << std::endl;
	delete this->_brain;
}

Cat & Cat::operator=(Cat const & rhs)
{
	// std::cout << "Assignment operator Cat called" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.getType();
		*this->_brain = *rhs._brain; //deep copy
		// this->_brain = rhs._brain; // shallow copy
	}
	return *this;
}

void	Cat::setName(std::string & name)
{
	this->_name = name;
}

void	Cat::makeSound(void) const
{
	std::cout << type << ": nyanyynanyannanyanynnanyanynanyannay" << std::endl;
}

Brain	*Cat::getAddrBrain(void) const
{
	return _brain;
}

void	Cat::printIdea(int i) const
{
	if (i >= 0 && i < 100)
		std::cout << this->_name <<" idea[" << i << "] is : " << this->_brain->_ideas[i]<< std::endl;
	else
		std::cout << "Error on index" << std::endl;
}

void	Cat::setIdea(int i, std::string new_idea)
{
	if (i >= 0 && i < 100)
		this->_brain->_ideas[i] = new_idea;
	else
		std::cout << "Error on index" << std::endl;
}