/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:51:05 by trobert           #+#    #+#             */
/*   Updated: 2023/01/18 10:28:19 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
// #define BLU "\e[1;94m"
// #define GRN "\e[1;92m"
// #define RED "\e[1;91m"

int main(void)
{
	try 
	{
		std::cout << "////////// ShrubberyCreationForm, test with signed 2 times --> Failed to execute ////////// " << std::endl;
		AForm *firstForm = new ShrubberyCreationForm("target1");
		Bureaucrat firstMan("Georges", 100); // change here the nbr between (1-150)
		std::cout << std::endl;
		
		std::cout << *firstForm;  // check form status
		std::cout << std::endl;

		firstMan.signForm(*firstForm); // success
		std::cout << std::endl;
		
		std::cout << *firstForm;  // check form status
		std::cout << std::endl;

		firstMan.signForm(*firstForm); //if you signed 2 times
		firstMan.executeForm(*firstForm);
		delete firstForm;
	}
	catch (std::exception &e)
	{
		std::cerr << "Couldn't instanciate Bureaucrat because : " << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;


	try
	{
		std::cout << "////////// RobotomyRequestForm, test with grade too low --> Failed to execute //////////" << std::endl;
		AForm *secondForm = new RobotomyRequestForm("target2");
		Bureaucrat secondMan("Craig", 73);
		std::cout << std::endl;

		secondMan.signForm(*secondForm); // grade too low
		secondMan.increment();
		secondMan.signForm(*secondForm); // can sign now
		secondMan.executeForm(*secondForm); //grade too low
		
		std::cout << std::endl;
		std::cout << *secondForm;
		delete secondForm;
	}
	catch (std::exception &e)
	{
		std::cerr << "Couldn't instanciate Bureaucrat because : " << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;


	try
	{
		std::cout << "////////// RobotomyRequestForm --> Succeed to execute //////////" << std::endl;
		AForm *secondForm = new RobotomyRequestForm("target2");
		Bureaucrat secondMan("Craig", 30);
		std::cout << std::endl;

		secondMan.signForm(*secondForm); // can sign now
		secondMan.executeForm(*secondForm); //grade too low
		
		std::cout << std::endl;
		std::cout << *secondForm;
		delete secondForm;
	}
	catch (std::exception &e)
	{
		std::cerr << "Couldn't instanciate Bureaucrat because : " << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;


	try
	{
		std::cout << "/////////////// PresidentialPardonForm, with not signed yet --> Succeed to execute //////////" << std::endl;
		AForm *thirdForm = new PresidentialPardonForm("Nicki Minaj");
		Bureaucrat firstWoman("Cardi B", 1);
		std::cout << std::endl;
		
		firstWoman.executeForm(*thirdForm); // need to sign it first
		firstWoman.signForm(*thirdForm);
		firstWoman.executeForm(*thirdForm);
		std::cout << std::endl;
		
		std::cout << *thirdForm;
		std::cout << std::endl;
		delete thirdForm;
	}
	catch (std::exception &e)
	{
		std::cerr << "Couldn't instanciate Bureaucrat because : " << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;


	try
	{
		std::cout << "/////////////// PresidentialPardonForm, with sign and execute form form --> Succeed to execute //////////" << std::endl;
		AForm *thirdForm = new PresidentialPardonForm("Nicki Minaj");
		Bureaucrat firstWoman("Cardi B", 1);
		std::cout << std::endl;
		
		thirdForm->beSigned(firstWoman);
		thirdForm->execute(firstWoman);
		std::cout << std::endl;
		
		std::cout << *thirdForm;
		std::cout << std::endl;
		delete thirdForm;
	}
	catch (std::exception &e)
	{
		std::cerr << "Couldn't instanciate Bureaucrat because : " << e.what() << std::endl;
	}
	std::cout << std::endl;

    return 0;
}
