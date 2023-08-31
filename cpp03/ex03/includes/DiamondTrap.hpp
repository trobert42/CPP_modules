/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:57:34 by trobert           #+#    #+#             */
/*   Updated: 2023/01/16 10:49:56 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>
#include <string>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);

		DiamondTrap(DiamondTrap const & cpy);

		~DiamondTrap(void);
	
		DiamondTrap & operator=(DiamondTrap const & rhs);
		
		void 	attack(const std::string& target);
		void 	whoAmI(void) const;
		void 	printInfoChar(void) const;


	private:
		std::string _name;
};

#endif