/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:37:27 by trobert           #+#    #+#             */
/*   Updated: 2023/01/16 14:03:14 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"

AAnimal::AAnimal(void) : type("Default")
{
	std::cout << "Default AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type)
{
	std::cout << "Parametric AAnimal constructor called with \"" << type << "\"" << std::endl;
}

AAnimal::AAnimal(AAnimal const & cpy)
{
	std::cout << "Copy AAnimal constructor called" << std::endl;
	*this = cpy;
}

AAnimal::~AAnimal(void)
{
	std::cout << "Destructor AAnimal called" << std::endl;
}

AAnimal & AAnimal::operator=(AAnimal const & rhs)
{
	// std::cout << "Assignment operator AAnimal called" << std::endl;
	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}

std::string AAnimal::getType(void) const
{
	return this->type;
}