/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:49:04 by trobert           #+#    #+#             */
/*   Updated: 2023/01/16 11:23:16 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);

		WrongAnimal(WrongAnimal const & cpy);

		virtual ~WrongAnimal(void);

		WrongAnimal & operator=(WrongAnimal const & rhs);
		
		std::string getType(void) const;
		void makeSound(void) const;


	protected:
		std::string type;
};

#endif