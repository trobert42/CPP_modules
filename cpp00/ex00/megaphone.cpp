/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:26:46 by trobert           #+#    #+#             */
/*   Updated: 2022/12/17 10:56:43 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if (ac > 1)
	{
		for (int i(1); i < ac; i++)
		{
			std::string tmpString (av[i]);
			for (int j(0); j < (int)tmpString.length(); j++)
				std::cout << (char) std::toupper(tmpString[j]);
		}
		std::cout << std::endl;
	}
	return (0); 
}
