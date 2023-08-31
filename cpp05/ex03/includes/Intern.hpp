/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:41:15 by trobert           #+#    #+#             */
/*   Updated: 2023/01/04 13:31:35 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern
{
	public:
		Intern(void);

		Intern(Intern const & cpy);

		~Intern(void);

		Intern & operator=(Intern const & rhs);

		AForm	*makeForm(std::string const & nameForm, std::string const & target) const;

		class NotExistingFormException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("form doesn't exist");
				}
		};
};

#endif