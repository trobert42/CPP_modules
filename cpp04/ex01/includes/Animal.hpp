/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:35:01 by trobert           #+#    #+#             */
/*   Updated: 2023/01/16 14:12:34 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	public:
		Animal(void);
		Animal(std::string type);

		Animal(Animal const & cpy);

		virtual ~Animal(void);

		Animal & operator=(Animal const & rhs);
		
		std::string 	getType(void) const;
		virtual void 	makeSound(void) const;


	protected:
		std::string type;
};

#endif