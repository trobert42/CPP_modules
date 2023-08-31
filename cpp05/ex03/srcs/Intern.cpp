/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:41:01 by trobert           #+#    #+#             */
/*   Updated: 2023/01/18 10:52:04 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

Intern::Intern(void)
{
	std::cout << "Default constructor Intern called" << std::endl;
}

Intern::Intern(Intern const & cpy)
{
	std::cout << "Copy constructor Intern called" << std::endl;
	*this = cpy;
}

Intern::~Intern(void)
{
	std::cout << "Destructor Intern for called" << std::endl;
}

Intern & Intern::operator=(Intern const & rhs)
{
	(void)rhs;
	std::cout << "Assignment operator Intern called" << std::endl;
	return *this;
}

AForm	*Intern::makeForm(std::string const & nameForm, std::string const & target) const
{
	std::string tab[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	
	int index = 0;
	for (; index < 3; index++)
	{
		if (nameForm == tab[index])
			break ;
	}

	switch (index)
	{
		case 0:
			return new ShrubberyCreationForm(target);
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new PresidentialPardonForm(target);
		default:
			throw NotExistingFormException();
			return NULL;
	}
}