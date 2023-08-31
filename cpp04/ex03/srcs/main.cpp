/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:20:43 by trobert           #+#    #+#             */
/*   Updated: 2022/12/27 17:13:05 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"
#include "../includes/MateriaSource.hpp"

int main()
{
	/////////////////////// TESTING GIVEN MAIN //////////////////////////
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	
	///////////////////////// TESTING MY MAIN //////////////////////////
	// ICharacter* me = new Character("me");
	// ICharacter* bob = new Character("bob");
	// AMateria* tmp = new Ice("ice");
	// AMateria* tmp2 = new Ice("ice");
	// AMateria* tmp3 = new Ice("ice");
	// AMateria* tmp4 = new Ice("ice");
	// AMateria* tmp5 = new Ice("ice");

	// std::cout << "TESTING CLONE FUNCTION" << std::endl;
	// AMateria *clone = tmp->clone();
	// std::cout << "tmp address : " << tmp << std::endl;
	// std::cout << "clone address : " << clone << std::endl;
	// delete clone;
	// std::cout << std::endl;

	// std::cout << "TESTING SKILLS" << std::endl;
	// me->equip(tmp); //equiping ice skill
	// me->equip(tmp2); //equiping ice skill
	// me->equip(tmp3); //equiping ice skill
	// me->equip(tmp4); //equiping ice skill
	// me->printInventory();
	// std::cout << std::endl;

	// me->equip(tmp5); //equiping one more but no place
	// std::cout << std::endl;

	// me->printInventory();
	// std::cout << std::endl;

	// me->unequip(2); //testing rm on nothing
	// me->unequip(3); //testing rm on nothing
	// me->unequip(4); //testing wrong index
	// me->unequip(3); //testing rm on nothing
	// delete tmp3;
	// delete tmp4;
	// delete tmp5;
	// std::cout << std::endl;

	// me->printInventory();
	// me->use(0, *bob); // * shoots an ice bolt at bob *
	// me->use(-1, *bob); // testing wrong index
	// std::cout << std::endl;
	
	// me->unequip(0);
	// me->use(0, *bob); // no more materia
	// me->use(1, *bob); // tmp2 ice still here
	// me->printInventory();
	// std::cout << std::endl;

	// me->equip(tmp2); // materia already in inventory[1]
	// me->equip(tmp); // reputting tmp in inventory[0]
	// me->printInventory();
	// std::cout << std::endl;

	// delete bob;
	// delete me;

	// std::cout << "TESTING DEEP COPY" << std::endl;

	// Character *me = new Character("me");
	// Character *copy;

	// AMateria *materia = new Ice("ice");
	// me->equip(materia);
	// copy = new Character(*me);
	// std::cout << std::endl;

	// std::cout << me->getName() << std::endl;
	// me->printInventory();
	// std::cout << std::endl;

	// std::cout << copy->getName() << std::endl;
	// copy->printInventory();
	// std::cout << std::endl;

	// delete me;
	// delete copy;

	return 0;
}
