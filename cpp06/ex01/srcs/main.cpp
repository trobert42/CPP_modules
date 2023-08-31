/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:28:55 by trobert           #+#    #+#             */
/*   Updated: 2023/02/06 14:29:35 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Convert.hpp"

int main(void)
{
	Data 		dataBefore;
	Data		*dataAfter = NULL;
	uintptr_t	retValue;

	dataBefore.nbr = 42;
	dataBefore.bestFood = "Thai Food";
	
	std::cout << "Comparing the Data address before the conversion" << std::endl
		<< "dataBefore address = " << &dataBefore << std::endl
		<< "dataAfter address = " << dataAfter << std::endl << std::endl;

	retValue = serialize(&dataBefore);
	dataAfter = deserialize(retValue);

	std::cout << "Comparing the Data address and info after the conversion" << std::endl
		<< "retValue address = " << retValue << std::endl
		<< "dataBefore address = " << &dataBefore << std::endl
		<< "dataAfter address = " << dataAfter << std::endl
		<< "dataBefore.nbr = " << dataBefore.nbr << std::endl
		<< "dataAfter->nbr = " << dataAfter->nbr << std::endl
		<< "dataBefore.bestFood = " << dataBefore.bestFood << std::endl
		<< "dataAfter->bestFood = " << dataAfter->bestFood << std::endl;

	return 0;
}