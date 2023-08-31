/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:25:36 by trobert           #+#    #+#             */
/*   Updated: 2023/02/10 21:22:05 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"
#include <list>

int main()
{
	std::cout << "---------- MY MAIN ----------" << std::endl;

	MutantStack<int> mutant1;
	if (mutant1.empty())
		std::cout << "it is empty, as expected...!" << std::endl << std::endl;
	
	std::cout << "*adding 5 numbers into the stack*" << std::endl;
	mutant1.push(1);
	mutant1.push(2);
	mutant1.push(3);
	mutant1.push(4);
	mutant1.push(5);
	for (MutantStack<int>::iterator it = mutant1.begin(); it != mutant1.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::cout << std::endl << "Size of the MutantStack is : " << mutant1.size() << std::endl;
	std::cout << "Top element of mutant1 MutantStack is : " << mutant1.top() << std::endl << std::endl;

	std::cout << "*removing the lastest element inserted*" << std::endl;
	mutant1.pop();
	for (MutantStack<int>::iterator it = mutant1.begin(); it != mutant1.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;

	std::cout << "*initializing a second MutantStack with the first one and adding some numbers*" << std::endl;

	MutantStack<int> mutant2(mutant1);
	mutant2.push(42);
	mutant2.push(42);
	mutant2.push(42);
	mutant2.push(42);
	mutant2.push(42);
	for (MutantStack<int>::iterator it = mutant2.begin(); it != mutant2.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;

	std::cout << "*iterating three times from the top of the MutantStack*" << std::endl;
	MutantStack<int>::iterator iter = mutant2.begin();
	std::cout << "iter++" << std::endl;
	iter++;
	std::cout << "iter++" << std::endl;
	iter++;
	std::cout << "iter++" << std::endl;
	iter++;
	std::cout << "iter value is : " << *iter << std::endl;
	std::cout << "iter--" << std::endl;
	iter--;
	std::cout << "iter value is : " << *iter << std::endl;

	// std::cout << "---------- GIVEN MAIN WITH MUTANTSTACK ----------" << std::endl;

	// MutantStack<int> mstack;
	// mstack.push(5);
	// mstack.push(17);
	// std::cout << mstack.top() << std::endl;
	// mstack.pop();
	// std::cout << mstack.size() << std::endl;
	// mstack.push(3);
	// mstack.push(5);
	// mstack.push(737);
	// //[...]
	// mstack.push(0);
	// MutantStack<int>::iterator it = mstack.begin();
	// MutantStack<int>::iterator ite = mstack.end();
	// ++it;
	// --it;
	// while (it != ite)
	// {
	// 	std::cout << *it << std::endl;
	// 	++it;
	// }
	// std::stack<int> s(mstack);

	// std::cout << "---------- GIVEN MAIN WITH LIST ----------" << std::endl;
	// std::list<int> mstack;
	// mstack.push_back(5);
	// mstack.push_back(17);
	// std::cout << mstack.back() << std::endl;
	// mstack.pop_back();
	// std::cout << mstack.size() << std::endl;
	// mstack.push_back(3);
	// mstack.push_back(5);
	// mstack.push_back(737);
	// // //[...]
	// mstack.push_back(0);
	// std::list<int>::iterator it = mstack.begin();
	// std::list<int>::iterator ite = mstack.end();
	// ++it;
	// --it;
	// while (it != ite)
	// {
	// 	std::cout << *it << std::endl;
	// 	++it;
	// }
	// std::list<int> s(mstack);

	return 0;
}