/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 22:27:57 by trobert           #+#    #+#             */
/*   Updated: 2022/12/27 17:08:37 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria(void) : type("Default")
{
	// std::cout << "Default constructor for /"Default/" AMateria called" << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type)
{
	// std::cout << "Parametric constructor for " << type << " AMateria called" << std::endl;
}

AMateria::AMateria(AMateria const & cpy)
{
	// std::cout << "Copy constructor for AMateria called" << std::endl;
	*this = cpy;
}

AMateria::~AMateria(void)
{
	// std::cout << "Destructor for AMateria called" << std::endl;
}

AMateria & AMateria::operator=(AMateria const & rhs)
{
	// std::cout << "Assignment operator for AMateria called" << std::endl;
	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}

std::string	const & AMateria::getType(void) const
{
	return this->type;
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* use skill on the target " << target.getName() << " *" << std::endl;
}