/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:37:27 by trobert           #+#    #+#             */
/*   Updated: 2023/01/16 16:03:13 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal(void) : type("Default")
{
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Parametric Animal constructor called with \"" << type << "\"" << std::endl;
}

Animal::Animal(Animal const & cpy)
{
	std::cout << "Copy Animal constructor called" << std::endl;
	*this = cpy;
}

Animal::~Animal(void)
{
	std::cout << "Destructor Animal called" << std::endl;
}

Animal & Animal::operator=(Animal const & rhs)
{
	// std::cout << "Assignment function Animal called" << std::endl;
	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}

std::string Animal::getType(void) const
{
	return this->type;
}

void	Animal::makeSound(void) const
{
	std::cout << "*Nothing happened*" << std::endl;
}