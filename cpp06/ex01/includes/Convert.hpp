/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:37:26 by trobert           #+#    #+#             */
/*   Updated: 2023/01/18 15:20:24 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <string>
#include <stdint.h>

struct Data
{
	int 			nbr;
	std::string 	bestFood;
};

uintptr_t 	serialize(Data *ptr);
Data* 		deserialize(uintptr_t raw);

#endif