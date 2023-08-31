/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:08:49 by trobert           #+#    #+#             */
/*   Updated: 2022/12/27 17:19:23 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Default Brain constructor called" << std::endl;
	for (int i(0); i < 50; i++)
		this->_ideas[i] = "I want to eat";
	for (int i(50); i < 100; i++)
		this->_ideas[i] = "I want to play";
}

Brain::Brain(Brain const & cpy)
{
	std::cout << "Copy Brain constructor called" << std::endl;
	*this = cpy;
}

Brain::~Brain(void)
{
	std::cout << "Destructor Brain called" << std::endl;
}

Brain & Brain::operator=(Brain const & rhs)
{
	// std::cout << "Assignment function Brain called" << std::endl;
	if (this != &rhs)
	{
		for (int i(0); i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return *this;
}