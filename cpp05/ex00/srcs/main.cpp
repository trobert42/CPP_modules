/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:51:05 by trobert           #+#    #+#             */
/*   Updated: 2022/12/28 16:52:29 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main(void)
{
	std::cout << "///// TEST WITH WRONG GRADES AT FIRST //////" << std::endl;
    try
    {
    	Bureaucrat firstMan("Georges", 151);
    }
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
    try
    {
    	Bureaucrat firstWoman("Georgettes", 0);
    }
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "///// TESTING WITH INCREMENTING GRADES //////" << std::endl;
	Bureaucrat secondMan("Giorgio", 2);
	try
    {
		secondMan.increment();
    }
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << secondMan;
	try
    {
		secondMan.increment();
    }
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << secondMan << std::endl;

	std::cout << "///// TESTING WITH DECREMENTING GRADES //////" << std::endl;
	Bureaucrat thirdMan("Giovanni", 149);
	try
    {
		thirdMan.decrement();
    }
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << thirdMan;
	try
    {
		thirdMan.decrement();
    }
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << thirdMan << std::endl;
	
    return 0;
}