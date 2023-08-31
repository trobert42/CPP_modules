/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:55:51 by trobert           #+#    #+#             */
/*   Updated: 2023/01/16 17:19:00 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(void);
		Form(std::string name, int signGrade, int execGrade);
		
		Form(Form const & cpy);

        ~Form(void);

		Form & operator=(Form const & rhs);
	
        std::string     getName(void) const;
    	int   			getSignGrade(void) const;
    	int   			getExecGrade(void) const;
		bool			getStatusSign(void) const;
		void			beSigned(Bureaucrat const & b);
	
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("grade too high");
				}
		};

		class GradeTooLowException : public std::exception 
		{
			public:
				virtual const char* what() const throw()
				{
					return ("grade too low");
				}
		};

		class AlreadySignedException : public std::exception 
		{
			public:
				virtual const char* what() const throw()
				{
					return ("already signed");
				}
		};

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;
};

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif