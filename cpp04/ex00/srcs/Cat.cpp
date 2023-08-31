/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:53:29 by trobert           #+#    #+#             */
/*   Updated: 2023/01/16 11:15:18 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat(Cat const & cpy) : Animal(cpy)
{
	std::cout << "Copy Cat constructor called" << std::endl;
	*this = cpy;
}

Cat::~Cat(void)
{
	std::cout << "Destructor Cat called" << std::endl;
}

Cat & Cat::operator=(Cat const & rhs)
{
	// std::cout << "Assignment function Cat called" << std::endl;
	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << type << ": nyanyynanyannanyanynnanyanynanyannay" << std::endl;
}