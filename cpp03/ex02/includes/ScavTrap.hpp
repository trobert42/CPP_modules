/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:34:26 by trobert           #+#    #+#             */
/*   Updated: 2023/01/16 10:32:23 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap 
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);

		ScavTrap(ScavTrap const & cpy);

		~ScavTrap(void);
		
		ScavTrap & operator=(ScavTrap const & rhs);
		
		void guardGate(void);
		void attack(const std::string& target);		
	
};

#endif