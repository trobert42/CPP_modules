/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:43:16 by trobert           #+#    #+#             */
/*   Updated: 2022/12/27 17:06:11 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	// std::cout << "Default constructor for cure called" << std::endl;
}

Cure::Cure(std::string const & type) : AMateria("cure"), _type(type)
{
	// std::cout << "Parametric constructor for cure called" << std::endl;
}

Cure::Cure(Cure const & cpy) : AMateria("cure")
{
	// std::cout << "Copy constructor for cure called" << std::endl;
	*this = cpy;
}

Cure::~Cure(void)
{
	// std::cout << "Destructor for cure called" << std::endl;
}

Cure & Cure::operator=(Cure const & rhs)
{
	// std::cout << "Assignment operator for cure called" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}

std::string const & Cure::getType(void) const
{
	return this->_type;
}


Cure* Cure::clone(void) const
{
	return new Cure(*this);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}