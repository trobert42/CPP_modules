/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 15:26:55 by trobert           #+#    #+#             */
/*   Updated: 2023/01/18 10:28:52 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(std::string target);
	
		RobotomyRequestForm(RobotomyRequestForm const & cpy);

		virtual ~RobotomyRequestForm(void);

		RobotomyRequestForm & operator=(RobotomyRequestForm const & cpy);
		
		void	execute(Bureaucrat const & executor) const;
	

	private:
		RobotomyRequestForm(void);
};

#endif