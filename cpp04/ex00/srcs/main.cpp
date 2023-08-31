/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:33:50 by trobert           #+#    #+#             */
/*   Updated: 2023/01/16 12:58:47 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main(void)
{
	std::cout << "--------------- Test with main given --------------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	delete j;
	delete meta;
	delete i;
	std::cout << std::endl;

	std::cout << "--------------- Test with WrongAnimal and WrongCat without the virtual function --------------" << std::endl;
	const WrongAnimal* k = new WrongCat();
	std::cout << std::endl;

	std::cout << k->getType() << " " << std::endl;
	std::cout << std::endl;

	k->makeSound();
	std::cout << std::endl;

	delete k;

	return 0;
}