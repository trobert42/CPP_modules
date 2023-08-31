/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:48:25 by trobert           #+#    #+#             */
/*   Updated: 2022/12/20 10:58:05 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	public:
		/*constructor and destructor*/
		HumanB(std::string name);
		~HumanB(void);
	
		void		setWeapon(Weapon &new_weapon);
		std::string	getName(void);
		void		setName(std::string new_name);
		void		attack(void) const;


	private:
		std::string _name;
		Weapon		*_weapon;	
};

#endif