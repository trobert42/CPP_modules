/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:02:58 by trobert           #+#    #+#             */
/*   Updated: 2022/12/16 11:40:55 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie (void)
{
	// std::cout << Default construtor called << std::endl;
}

Zombie::Zombie(std::string name)
{
	// std::cout << Parametric construtor called << std::endl;
	this->_name = name;
}

Zombie::~Zombie(void)
{
	// std::cout << Destructor called << std::endl;
	std::cout << this->_name << " has been destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}
