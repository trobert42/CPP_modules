/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:55:53 by trobert           #+#    #+#             */
/*   Updated: 2022/12/29 15:26:49 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm(void) : _name("Default"),  _target("Default"), _isSigned(false), _signGrade(1), _execGrade(1)
{
	std::cout << "Default constructor AForm called" << std::endl;	
}

AForm::AForm(std::string name, std::string target, int signGrade, int execGrade) : _name(name), _target(target), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	std::cout 
		<< "Parametric constructor AForm for \"" << this->getName() 
		<< "\" with sign grade " << this->getSignGrade()
		<< ", execute grade " << this->getExecGrade()
		<< " and target \"" << this->getTarget()
		<< "\" called" << std::endl;
}

AForm::AForm(AForm const & cpy) : _name(cpy.getName()), _target(cpy.getTarget()), _isSigned(cpy.getStatusSign()), _signGrade(cpy.getSignGrade()), _execGrade(cpy.getExecGrade())
{
	std::cout << "Copy constructor for " << this->getName() << " called" << std::endl;
	*this = cpy;
}

AForm::~AForm(void)
{
	std::cout << "Destructor AForm for " << this->getName() << " called" << std::endl;
}

AForm & AForm::operator=(AForm const & rhs)
{
	std::cout << "Assignment operator AForm for " << this->getName() << " called" << std::endl;
	if (this != &rhs)
	{
		this->_isSigned = rhs._isSigned;
		this->_target = rhs.getTarget();
	}
	return *this;
}

std::string	AForm::getName(void) const
{
	return this->_name;
}

std::string	AForm::getTarget(void) const
{
	return this->_target;
}

int	AForm::getSignGrade(void) const
{
	return this->_signGrade;
}

int	AForm::getExecGrade(void) const
{
	return this->_execGrade;
}

bool	AForm::getStatusSign(void) const
{
	return this->_isSigned;
}

void	AForm::beSigned(Bureaucrat const & b)
{
	if (b.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	if (this->_isSigned == true)
		throw AForm::AlreadySignedException();
	else
	{
		this->_isSigned = true;
		std::cout << b.getName() << " signed AForm " << this->getName() << std::endl;
	}
}

std::ostream & operator<<(std::ostream &o, AForm const & rhs)
{
	std::string tmp;

	if (rhs.getStatusSign() == true)
		tmp = "yes";
	else
		tmp = "no";
	
	o << " ----- Form information ----- " << std::endl
		<< "Form name: " << rhs.getName() << std::endl
		<< "Signed: " << tmp << std::endl
		<< "Grade to sign: " << rhs.getSignGrade() << std::endl
		<< "Grade to execute: " << rhs.getExecGrade() << std::endl
		<< "Target: " << rhs.getTarget() << std::endl
		<< " ---------------------------- " << std::endl;
	return o;
}