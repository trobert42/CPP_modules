/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:06:34 by trobert           #+#    #+#             */
/*   Updated: 2022/12/17 10:20:57 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

int main(int ac, char **av)
{
	std::string str;
	Harl		harl;
	
	if (ac < 2)
		return (std::cout << "Error, usage : ./harlfilter DEBUG/INFO/WARNING/ERROR/etc.." << std::endl, -1);
	str = av[1];
	harl.complain(str);
	return 0;
}