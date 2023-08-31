/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:55:51 by trobert           #+#    #+#             */
/*   Updated: 2022/12/16 11:44:26 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void)
{
	int	N = 5;
	Zombie *horde = zombieHorde(N, "Chris");
	Zombie ethan("Ethan");
	ethan.announce();

	if (horde)
	{
		for (int i(0); i < N; i++)
			horde[i].announce();
	}
	delete [] (horde);
	return (0);
}