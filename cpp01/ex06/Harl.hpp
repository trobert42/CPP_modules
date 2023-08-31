/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:52:33 by trobert           #+#    #+#             */
/*   Updated: 2022/12/17 10:15:52 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
	public:
		Harl(void);
		~Harl(void);
		void complain(std::string);

	private:
		void debug(void);		
		void info(void);		
		void warning(void);		
		void error(void);
		typedef void (Harl::*ptrComplain) (void);		
};

#endif