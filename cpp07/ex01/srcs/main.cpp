/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:28:55 by trobert           #+#    #+#             */
/*   Updated: 2023/02/09 13:34:31 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"
#include "../includes/whatever.hpp"
#include <iostream>

int main(void)
{
	std::cout << "-------------- TEST WITH INT TAB -------------- " << std::endl;
	int tab[3] = {0, 1, 2};

	iter(tab, 3, &increment);
	for (unsigned int i(0); i < 3; i++)
		std::cout << tab[i] << std::endl;
	std::cout << std::endl;


	std::cout << "-------------- TEST WITH DOUBLE TAB -------------- " << std::endl;
	double tab2[5] = {1.0, 3.4, 6.5, 7.7, 2.43};

	iter(tab2, 5, &increment);
	for (unsigned int i(0); i < 5; i++)
		std::cout << tab2[i] << std::endl;
	std::cout << std::endl;


	std::cout << "-------------- TEST WITH STRING TAB -------------- " << std::endl;
	char tab3[] = "abc";

	iter(tab3, 3, &increment);
	for (unsigned int i(0); i < 3; i++)
		std::cout << tab3[i] << std::endl;
	std::cout << std::endl;

	return 0;
}