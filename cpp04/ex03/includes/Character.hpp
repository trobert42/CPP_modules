/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:17:57 by trobert           #+#    #+#             */
/*   Updated: 2022/12/27 17:14:42 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character(void);
		Character(std::string name);
		
		Character(Character const & cpy);

		virtual ~Character(void);

		Character & operator=(Character const & rhs);

		virtual std::string const & getName(void) const;
		virtual void equip(AMateria *m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
		virtual void printInventory(void) const;


	private:
		static const int MAX_MATERIA = 4;
		std::string 	_name;
		AMateria		*_inventory[MAX_MATERIA];
};

#endif