/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:19:39 by trobert           #+#    #+#             */
/*   Updated: 2022/12/19 17:57:55 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	public:
		/*constructor and destructor*/
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
	
		std::string	getName(void);
		void		setName(std::string new_name);
		void		attack(void) const;


	private:
		std::string _name;
		Weapon 		&_weapon;
};

#endif