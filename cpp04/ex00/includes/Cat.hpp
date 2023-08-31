/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:53:25 by trobert           #+#    #+#             */
/*   Updated: 2022/11/21 18:44:46 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{
	public:
		Cat(void);

		Cat(Cat const & cpy);
		
		virtual ~Cat(void);
	
		Cat & operator=(Cat const & rhs);
		virtual void makeSound(void) const;
};

#endif
