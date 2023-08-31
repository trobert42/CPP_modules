/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:50:46 by trobert           #+#    #+#             */
/*   Updated: 2023/01/16 11:21:53 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "Default WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const & cpy) : WrongAnimal(cpy)
{
	std::cout << "Copy WrongCat constructor called" << std::endl;
	*this = cpy;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Destructor WrongCat called" << std::endl;
}

WrongCat & WrongCat::operator=(WrongCat const & rhs)
{
	// std::cout << "Assignment function WrongCat called" << std::endl;
	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}

void	WrongCat::makeSound(void) const
{
	std::cout << type << ": Meow" << std::endl;
}