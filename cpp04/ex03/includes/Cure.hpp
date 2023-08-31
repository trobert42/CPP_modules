/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:42:46 by trobert           #+#    #+#             */
/*   Updated: 2022/12/27 17:14:27 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(std::string const & type);

		Cure(Cure const & cpy);

		virtual ~Cure(void);

		Cure & operator=(Cure const & rhs);

		std::string const & getType(void) const;

		virtual Cure* clone(void) const;
		virtual void use(ICharacter& target);


	private:
		std::string	_type;
};

#endif