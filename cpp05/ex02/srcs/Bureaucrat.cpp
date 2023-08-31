/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:52:10 by trobert           #+#    #+#             */
/*   Updated: 2023/01/18 10:20:15 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150)
{
	std::cout << "Default constructor Bureaucrat for \"Default\" with grade 150 called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
	{
		std::cout 
			<< "Parametric constructor Bureaucrat for " << this->getName()
			<< " with grade " << this->getGrade() << " called" << std::endl;	
	}
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor Bureaucrat for " << this->getName() << " called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & cpy) : _name(cpy.getName())
{
	std::cout << "Copy constructor Bureaucrat for " << cpy.getName() << " called" << std::endl;	
	*this = cpy;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	std::cout << "Assignment operator Bureaucrat for" << this->getName() << " called" << std::endl;	
	if (this != &rhs)
		this->_grade = rhs.getGrade();
	return *this;
}

std::string Bureaucrat::getName(void) const
{
	return this->_name;
}

int	Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void	Bureaucrat::signForm(AForm & f)
{
	try 
	{
		f.beSigned(*this);
	}
	catch (std::exception &e)
	{
		std::cerr << this->_name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & f) const
{
	try
	{
		f.execute(*this);
	}
	catch (std::exception &e)
	{
		std::cerr << this->_name << " couldn't execute " << f.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::increment(void)
{
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= 1;
}

void	Bureaucrat::decrement(void)
{
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += 1;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs)
{
	o << rhs.getName() <<  ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return o;
}