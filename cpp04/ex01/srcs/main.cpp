/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:33:50 by trobert           #+#    #+#             */
/*   Updated: 2023/01/16 16:04:13 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int main(void)
{
	///////////////////////// TEST LEAKS  //////////////////////////////
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	///////////////////////// TEST FUNCTION MAKE SOUND FOR DOGS AND CATS //////////////////////////////
	// Animal *animals_tab[4];
	// for (int i(0); i < 2; i++)
	// 	animals_tab[i] = new Cat();
	// for (int i(2); i < 4; i++)
	// 	animals_tab[i] = new Dog();
	// std::cout << std::endl;

	// for (int i(0); i < 4; i++)
	// 	animals_tab[i]->makeSound();

	// std::cout << std::endl;

	// for (int i(0); i < 4; i++)
	// 	delete animals_tab[i];

	//////////////////////// TEST DEEP COPY ///////////////////////////////
	// Cat firstCat("firstCat");
	// Cat secondCat("secondCat");
	// std::cout << std::endl;
	
	// std::cout << "Printing default ideas of cats" << std::endl;
	// firstCat.setIdea(0, "Play with me slave");
	// firstCat.printIdea(0);
	// firstCat.printIdea(1);
	// secondCat.printIdea(0);
	// secondCat.printIdea(1);
	// std::cout << std::endl;
	
	// std::cout << "secondCat = firstCat" << std::endl;
	// secondCat = firstCat;
	// firstCat.printIdea(0);
	// firstCat.printIdea(1);
	// secondCat.printIdea(0);
	// secondCat.printIdea(1);
	// std::cout << std::endl;

	// std::cout << "Changing the first idea of firstCat and checking idea for both of them" << std::endl;
	// firstCat.setIdea(0, "Changed my mind, leave me alone");
	// firstCat.printIdea(0);
	// secondCat.printIdea(0);
	// std::cout << std::endl;
	
	// std::string	cpyCatName = "cpyCat";
	// std::cout << "Creating a cpy of firstCat called cpyCat" << std::endl;
	// Cat cpyCat(firstCat);
	// std::cout << "cpyCat brain address : " << cpyCat.getAddrBrain() << std::endl;
	// std::cout << "firstCat brain address : " << firstCat.getAddrBrain() << std::endl;
	// std::cout << std::endl;
	
	// cpyCat.setName(cpyCatName);
	// firstCat.printIdea(0);
	// firstCat.printIdea(1);
	// cpyCat.printIdea(0);
	// cpyCat.printIdea(1);
	// std::cout << "Changing the first idea of firstCat" << std::endl;
	// std::cout << "Changing the second idea of firstCat" << std::endl;
	// firstCat.setIdea(0, "Give me food human slave");
	// firstCat.setIdea(1, "Meow");
	// firstCat.printIdea(0);
	// firstCat.printIdea(1);
	// cpyCat.printIdea(0);
	// cpyCat.printIdea(1);
	// std::cout << std::endl;

	std::cout << std::endl;

	return 0;
}
