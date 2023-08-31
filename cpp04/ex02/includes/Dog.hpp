/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:22:04 by trobert           #+#    #+#             */
/*   Updated: 2022/12/21 22:13:28 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
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
		Brain 		*_brain;
		std::string	_name;
};

#endif
