/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 22:24:18 by trobert           #+#    #+#             */
/*   Updated: 2023/01/16 16:11:23 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	public:
		AMateria(void);
		AMateria(std::string const & type);

		AMateria(AMateria const & cpy);

		virtual ~AMateria(void);

		AMateria & operator=(AMateria const & rhs);
		
		std::string const & getType(void) const;

		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter& target);


	protected:
		std::string	type;
};

#endif