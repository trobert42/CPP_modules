/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:25:03 by trobert           #+#    #+#             */
/*   Updated: 2022/12/27 17:05:32 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	// std::cout << "Default constructor for ice called" << std::endl;
}

Ice::Ice(std::string const & type) : AMateria("ice"), _type(type)
{
	// std::cout << "Parametric constructor for ice called" << std::endl;
}

Ice::Ice(Ice const & cpy) : AMateria("ice")
{
	// std::cout << "Copy constructor for ice called" << std::endl;
	*this = cpy;
}

Ice::~Ice(void)
{
	// std::cout << "Destructor for ice called" << std::endl;
}

Ice & Ice::operator=(Ice const & rhs)
{
	// std::cout << "Assignment operator for ice called" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}

std::string const & Ice::getType(void) const
{
	return this->_type;
}


Ice* Ice::clone(void) const
{
	return new Ice(*this);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}