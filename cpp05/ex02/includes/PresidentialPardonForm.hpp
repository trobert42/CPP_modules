/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 15:46:26 by trobert           #+#    #+#             */
/*   Updated: 2023/01/18 10:02:11 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(std::string target);
	
		PresidentialPardonForm(PresidentialPardonForm const & cpy);

		virtual ~PresidentialPardonForm(void);

		PresidentialPardonForm & operator=(PresidentialPardonForm const & cpy);
		
		void	execute(Bureaucrat const & executor) const;
	
	
	private:
		PresidentialPardonForm(void);
};

#endif