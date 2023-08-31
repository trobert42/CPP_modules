/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:02:19 by trobert           #+#    #+#             */
/*   Updated: 2022/12/16 11:44:51 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include "Zombie.hpp"

class Zombie
{
	public:
		/*constructor and destructor*/
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
	
		void	announce(void);
		void	setName(std::string name);
	
	private:
		std::string _name;
};


#endif