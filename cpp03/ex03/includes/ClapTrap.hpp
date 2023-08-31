/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:31:59 by trobert           #+#    #+#             */
/*   Updated: 2023/01/16 10:41:36 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
	
		ClapTrap(ClapTrap const & cpy);

		~ClapTrap(void);

		ClapTrap & operator=(ClapTrap const & rhs);
	
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);


	protected:
		std::string	_name;
		int			_hitPoint;
		int			_energyPoint;
		int			_attkDmg;
};

#endif