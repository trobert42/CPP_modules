/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:53:11 by trobert           #+#    #+#             */
/*   Updated: 2022/12/27 17:23:36 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog(Dog const & cpy) : Animal(cpy)
{
	std::cout << "Copy Dog constructor called" << std::endl;
	*this = cpy;
}

Dog::~Dog(void)
{
	std::cout << "Destructor Dog called" << std::endl;
}

Dog & Dog::operator=(Dog const & rhs)
{
	// std::cout << "Assignment function Dog called" << std::endl;
	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << type << ": wouafwouaf" << std::endl;
}