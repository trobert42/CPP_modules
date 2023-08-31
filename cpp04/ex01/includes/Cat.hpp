/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:53:25 by trobert           #+#    #+#             */
/*   Updated: 2023/01/16 13:02:02 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(std::string name);

		Cat(Cat const & cpy);
		
		virtual ~Cat(void);
	
		Cat & operator=(Cat const & rhs);
	
		void			setName(std::string & name);
		virtual void	makeSound(void) const;
		Brain			*getAddrBrain(void) const;
		void			printIdea(int i) const;
		void			setIdea(int i, std::string new_idea);


	private:
		Brain 		*_brain;
		std::string	_name;
};

#endif
