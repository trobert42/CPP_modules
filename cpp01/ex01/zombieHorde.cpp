/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:54:42 by trobert           #+#    #+#             */
/*   Updated: 2022/12/16 11:38:17 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N > 0)
	{
		Zombie *horde = new Zombie[N];
		for(int i(0); i < N; i++)
			horde[i].setName(name);
		return (horde);
	}
	return NULL;
}