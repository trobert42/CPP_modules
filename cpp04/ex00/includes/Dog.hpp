/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:22:04 by trobert           #+#    #+#             */
/*   Updated: 2022/11/21 18:44:42 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{
	public:
		Dog(void);

		Dog(Dog const & cpy);
		
		virtual ~Dog(void);
	
		Dog & operator=(Dog const & rhs);
		virtual void makeSound(void) const;
};

#endif
