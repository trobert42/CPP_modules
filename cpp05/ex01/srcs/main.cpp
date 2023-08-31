/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:51:05 by trobert           #+#    #+#             */
/*   Updated: 2023/01/18 09:27:55 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main(void)
{
	std::cout << "///// BASIC TEST FOR SUCCESS SIGN //////" << std::endl;
	try
	{
    	Bureaucrat firstMan("Georges", 42);
		Form schoolForm("42 school inscription", 42, 42);
		std::cout << std::endl;

		std::cout << schoolForm; // form at first
		std::cout << std::endl;
		
		firstMan.signForm(schoolForm); //he can successfully sign
		std::cout << std::endl;

		std::cout << schoolForm; // check on form status
		std::cout << std::endl;

		firstMan.signForm(schoolForm); // can't sign again
		std::cout << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << "Couldn't instanciate because : " << e.what() << std::endl; // line not read
	}
	std::cout << std::endl;


	std::cout << "///// BASIC TEST WITH BUREAUCRAT TOO LOW GRADE //////" << std::endl;
	try
	{
		Bureaucrat secondMan("Johnny", 13);
		Form ciaForm("CIA inscription", 2, 2); // can construct the form because grades are valid 
		secondMan.signForm(ciaForm); // can't sign, grade too low
		std::cout << ciaForm; // check on form status
		//end of block try, so destructor called!
	}
	catch (std::exception &e)
	{
		std::cerr << "Couldn't create CIA inscription because : " << e.what() << std::endl; // line not read
	}
	std::cout << std::endl;
	

	std::cout << "///// TRYING INCREMENTING INSIDE THE TRY BLOCK AND THEN SIGNFORM //////" << std::endl;
	try
	{
		Form ciaForm("CIA inscription", 2, 2);
		Bureaucrat god("Chuck Norris", 3);
		god.increment(); // grade is now 2
		std::cout << god;
		god.increment(); // grade is now 1
		std::cout << god;
		god.increment(); // grade is now 0
		//here, it goes to catch part because exception catched. But before, destructors called

		std::cout << god; // it doesnt read that line!
		god.signForm(ciaForm); // it doesn't read that line!
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

    return 0;
}