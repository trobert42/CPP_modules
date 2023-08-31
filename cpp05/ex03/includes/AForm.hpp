/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:55:51 by trobert           #+#    #+#             */
/*   Updated: 2023/01/01 14:38:22 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm(void);
		AForm(std::string name, std::string target, int signGrade, int execGrade);

		AForm(AForm const & cpy);

        virtual ~AForm(void);

		AForm & operator=(AForm const & rhs);
	
        std::string     getName(void) const;
        std::string     getTarget(void) const;
    	int   			getSignGrade(void) const;
    	int   			getExecGrade(void) const;
		bool			getStatusSign(void) const;
		void			beSigned(Bureaucrat const & b);
		virtual void	execute(Bureaucrat const & executor) const = 0;
	
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
					return("form has been already signed");
				}
		};

		class NotSignedYetException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("form need to be signed to execute it");
				}
		};


	private:
		const std::string	_name;
		std::string			_target;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;
};

std::ostream & operator<<(std::ostream & o, AForm const & rhs);

#endif