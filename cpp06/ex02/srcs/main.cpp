/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:28:55 by trobert           #+#    #+#             */
/*   Updated: 2023/02/06 14:45:51 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include <stdexcept>
#include <typeinfo>

class A;
class B;
class C;

Base *generate(void)
{
	Base 	*parent;
	
	std::srand(time(NULL));
	int	rand = std::rand() % 3;

	switch (rand)
	{
		case 1:
			return parent = dynamic_cast<Base *>(new A);
		case 2:
			return parent = dynamic_cast<Base *>(new B);
		default:
			return parent = dynamic_cast<Base *>(new C);
	}
	return NULL;
};

void identifyByPtr(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "instance of class A was created" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "instance of class B was created" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "instance of class C was created" << std::endl;
};

void identifyByRef(Base &p)
{
	try 
	{
		Base test = dynamic_cast<A&>(p);
		std::cout << "instance of class A was created" << std::endl;
	}
	catch (std::bad_cast &bc)
	{
		// std::cout << "Bad cast" << std::endl;
	}
	try 
	{
		Base test = dynamic_cast<B&>(p);
		std::cout << "instance of class B was created" << std::endl;
	}
	catch (std::bad_cast &bc)
	{
		// std::cout << "Bad cast" << std::endl;
	}
	try 
	{
		Base test = dynamic_cast<C&>(p);
		std::cout << "instance of class C was created" << std::endl;
	}
	catch (std::bad_cast &bc)
	{
		// std::cout << "Bad cast" << std::endl;
	}
};

int main(void)
{
	Base *test;

	test = generate();
	identifyByPtr(test);
	identifyByRef(*test);
	
	if (test)
		delete test ;

	return 0;
}