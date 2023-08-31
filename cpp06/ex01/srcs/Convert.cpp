/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:38:36 by trobert           #+#    #+#             */
/*   Updated: 2023/01/18 15:32:16 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Convert.hpp"

uintptr_t serialize(Data *ptr)
{
	uintptr_t notSignedType;
	
	notSignedType = reinterpret_cast<uintptr_t>(ptr);
	return notSignedType;
}

Data *deserialize(uintptr_t raw)
{
	Data *newData;

	newData = reinterpret_cast<Data *>(raw);
	return newData;
}