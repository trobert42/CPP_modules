/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:55:53 by trobert           #+#    #+#             */
/*   Updated: 2023/01/18 10:21:28 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form(void) : _name("Default"), _isSigned(false), _signGrade(1), _execGrade(1)
{
	std::cout << "Default constructor Form called" << std::endl;	
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	else
	{
		std::cout 
			<< "Parametric constructor Form for " << this->getName() 
			<< " with grade to sign " << this->getSignGrade()
			<< " and grade to execute " << this->getExecGrade()
			<< " called" << std::endl;
	}
}

Form::Form(Form const & cpy) : _name(cpy.getName()), _isSigned(cpy.getStatusSign()), _signGrade(cpy.getSignGrade()), _execGrade(cpy.getExecGrade())
{
	std::cout << "Copy constructor Form for " << cpy.getName() << " called" << std::endl;
	*this = cpy;
}

Form::~Form(void)
{
	std::cout << "Destructor Form for " << this->getName() << " called" << std::endl;
}

Form & Form::operator=(Form const & rhs)
{
	std::cout << "Assignment operator Form for " << this->getName() << " called" << std::endl;
	if (this != &rhs)
		this->_isSigned = rhs._isSigned;
	return *this;
}

std::string	Form::getName(void) const
{
	return this->_name;
}

int	Form::getSignGrade(void) const
{
	return this->_signGrade;
}

int	Form::getExecGrade(void) const
{
	return this->_execGrade;
}

bool	Form::getStatusSign(void) const
{
	return this->_isSigned;
}

void	Form::beSigned(Bureaucrat const & b)
{
	if (b.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	else if (this->_isSigned == true)
		throw Form::AlreadySignedException();
	else
	{
		this->_isSigned = true;
		std::cout << b.getName() << " signed " << this->getName() << std::endl;	
	}
}


std::ostream & operator<<(std::ostream &o, Form const & rhs)
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
		<< " ---------------------------- " << std::endl;

	return o;
}