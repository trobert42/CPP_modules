/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:48:24 by trobert           #+#    #+#             */
/*   Updated: 2022/12/16 12:30:38 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string msg = "HI THIS IS BRAIN";
	std::string *stringPTR = &msg;
	std::string& stringREF = msg;

	std::cout << "msg value : " << msg << std::endl;
	std::cout << "ptr value : " << *stringPTR << std::endl;
	std::cout << "ref value : " << stringREF << std::endl;

	return (0);
}