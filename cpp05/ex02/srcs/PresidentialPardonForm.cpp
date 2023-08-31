/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 15:47:11 by trobert           #+#    #+#             */
/*   Updated: 2023/01/18 10:17:40 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", "Default", 25, 5)
{
	std::cout << "Default constructor PresidentialPardonForm called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", target, 25, 5)
{
	std::cout
		<< "Parametric constructor for " << this->getName() 
		<< " with sign grade " << this->getSignGrade()
		<< ", execute grade " << this->getExecGrade()
		<< " and target \"" << this->getTarget()
		<< "\" called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & cpy) : AForm(cpy.getName(), cpy.getTarget(), cpy.getSignGrade(), cpy.getExecGrade())
{
	std::cout << "Copy constructor for " << this->getName() << " called" << std::endl;
	*this = cpy;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "Destructor for " << this->getName() << " called" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	std::cout << "Assignment operator PresidentialPardonForm called" << std::endl;
	if (this != &rhs)
		AForm::operator=(rhs);
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > AForm::getExecGrade())
		throw AForm::GradeTooLowException();
	else if (this->getStatusSign() == false)
		throw AForm::NotSignedYetException();
	else
	{
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
		std::cout << this->getTarget() << " has been pardonned by Zaphod BeebleBrox" << std::endl;
	}
}
