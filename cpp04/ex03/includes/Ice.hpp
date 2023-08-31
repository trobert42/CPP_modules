/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 22:49:44 by trobert           #+#    #+#             */
/*   Updated: 2023/01/16 16:11:50 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(std::string const & type);

		Ice(Ice const & cpy);

		virtual ~Ice(void);

		Ice & operator=(Ice const & rhs);

		std::string const & getType(void) const;

		virtual Ice* clone(void) const;
		virtual void use(ICharacter& target);


	private:
		std::string	_type;
};

#endif