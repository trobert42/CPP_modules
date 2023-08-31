/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:08:59 by trobert           #+#    #+#             */
/*   Updated: 2022/12/20 19:26:06 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class Brain 
{
	public:
		Brain(void);

		Brain(Brain const & cpy);

		~Brain(void);
		
		Brain & operator=(Brain const & rhs);
		
		std::string _ideas[100];
};

#endif
