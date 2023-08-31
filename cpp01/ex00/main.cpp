/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:01:41 by trobert           #+#    #+#             */
/*   Updated: 2022/12/16 11:37:05 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

/*we can also create an another .h with these prototypes*/
Zombie* newZombie( std::string name );
void	randomChump( std::string name );

void	test(Zombie z)
{
	std::cout 
		<< " ----------- " << std::endl
		<< "Copy of Zombie jill" << std::endl
		<< " ----------- " << std::endl;
	z.announce();
	return ;
}

int main(void)
{
	Zombie *chris = newZombie("Chris");
	chris->announce();
	std::cout << std::endl;

	/*we can't use it outside of the class*/
	randomChump("Leon");
	std::cout << std::endl;

	/*we can free the memory of zombie Chris whenever we want,
	delete() calls the destructor of the class*/
	delete(chris);
	std::cout << std::endl;
	
	/*just for the main function, can't modify its value outside*/
	Zombie jill("Jill");
	
	/*it allocates one of jill and it deletes it when "return;"*/
	test(jill);
	std::cout << std::endl;

	return (0);
}