/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 15:28:04 by trobert           #+#    #+#             */
/*   Updated: 2023/01/18 10:17:31 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", "Default", 72, 45)
{
	std::cout << "Default constructor RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", target, 72, 45)
{
	std::cout
		<< "Parametric constructor for " << this->getName() 
		<< " with sign grade " << this->getSignGrade()
		<< ", execute grade " << this->getExecGrade()
		<< " and target \"" << this->getTarget()
		<< "\" called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & cpy) : AForm(cpy.getName(), cpy.getTarget(), cpy.getSignGrade(), cpy.getExecGrade())
{
	std::cout << "Copy constructor for " << this->getName() << " called" << std::endl;
	*this = cpy;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Destructor for " << this->getName() << " called" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	std::cout << "Assignment operator RobotomyRequestForm called" << std::endl;
	if (this != &rhs)
		AForm::operator=(rhs);
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > AForm::getExecGrade())
		throw AForm::GradeTooLowException();
	else if (this->getStatusSign() == false)
		throw AForm::NotSignedYetException();
	else
	{
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
		std::cout << "Drrrrr-drrrr-drrrrrrrrrrr" << std::endl;
		std::srand(time(NULL));
		int	rand = std::rand() % 2;
		if (rand == 0)
			std::cout << "Robotomy operation for " << this->getTarget() << " has failed" << std::endl;
		else
			std::cout << "Robotomy operation for " << this->getTarget() << " has succeed" << std::endl;
	}
}
