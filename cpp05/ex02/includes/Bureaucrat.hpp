/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:52:44 by trobert           #+#    #+#             */
/*   Updated: 2023/01/02 13:18:21 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    public:
        Bureaucrat(void);
        Bureaucrat(std::string name, int grade);
		
		Bureaucrat(Bureaucrat const & cpy);

        ~Bureaucrat(void);

		Bureaucrat & operator=(Bureaucrat const & rhs);
        std::string     getName(void) const;
    	int   			getGrade(void) const;
		void			signForm(AForm & f);
		void			executeForm(AForm const & f) const;

		void	increment(void);
		void	decrement(void);
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade too high, cannot be higher than 1.");
				}
		};

		class GradeTooLowException : public std::exception 
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade too low, cannot be lower than 150.");
				}
		};

    private:
        const std::string   _name;
    	int					_grade;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif