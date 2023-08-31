/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:22:04 by trobert           #+#    #+#             */
/*   Updated: 2023/01/16 14:10:33 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(std::string name);

		Dog(Dog const & cpy);
		
		virtual ~Dog(void);
	
		Dog & operator=(Dog const & rhs);
		void			setName(std::string name);
		virtual void	makeSound(void) const;
		Brain			*getAddrBrain(void) const;
		void			printIdea(int i) const;
		void			setIdea(int i, std::string new_idea);


	private:
		Brain 			*_brain;
		std::string		_name;
};

#endif
