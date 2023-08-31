/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:35:01 by trobert           #+#    #+#             */
/*   Updated: 2023/01/16 13:28:38 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal
{
	public:
		AAnimal(void);
		AAnimal(std::string type);

		AAnimal(AAnimal const & cpy);

		virtual ~AAnimal(void);

		AAnimal & operator=(AAnimal const & rhs);
		
		std::string getType(void) const;
		virtual void makeSound(void) const = 0;


	protected:
		std::string type;
};

#endif