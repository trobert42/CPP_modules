/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:28:55 by trobert           #+#    #+#             */
/*   Updated: 2023/02/10 21:22:36 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"
#include <list>
#include <vector>

int main(void)
{
	std::cout << "-------- TEST VECTOR CONTAINER --------" << std::endl;
	std::vector<int> v;
	v.push_back(32);
	v.push_back(432);
	v.push_back(1);
	v.push_back(-11);

	int nbrToFind = 4;
	std::cout << "*nbr not inside container*" << std::endl;
	try
	{
		easyfind(v, nbrToFind);
		std::cout << "Found the nbr " << nbrToFind << " inside the container" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception catched : " << e.what() << std::endl;
	}
	
	v.push_back(nbrToFind);
	std::cout << "Adding the nbr 4 inside the list of nbr" << std::endl << std::endl;
	

	std::cout << "*nbr inside container*" << std::endl;
	try
	{
		easyfind(v, nbrToFind);
		std::cout << "Found the nbr " << nbrToFind << " inside the container" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception catched : " << e.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << "-------- TEST LIST CONTAINER --------" << std::endl;
	std::list<int> l;
	l.push_back(32);
	l.push_back(432);
	l.push_back(1);
	l.push_back(-11);

	int nbrToFind2 = 432;
	std::cout << "*nbr inside container*" << std::endl;
	try
	{
		easyfind(l, nbrToFind2);
		std::cout << "Found the nbr " << nbrToFind2 << " inside the container" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception catched : " << e.what() << std::endl;
	}

	return 0;
}