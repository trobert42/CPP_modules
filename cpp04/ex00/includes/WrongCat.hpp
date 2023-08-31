/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:50:44 by trobert           #+#    #+#             */
/*   Updated: 2022/11/21 18:58:47 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);

		WrongCat(WrongCat const & cpy);
		
		virtual ~WrongCat(void);
	
		WrongCat & operator=(WrongCat const & rhs);
		void makeSound(void) const;
};

#endif
