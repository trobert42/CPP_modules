/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:51:05 by trobert           #+#    #+#             */
/*   Updated: 2023/01/18 10:39:47 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

int main(void)
{
	Intern	firstIntern;
	std::cout << std::endl;

	try
	{
		std::cout << "/////////////// RobotomyRequestForm --> Succeed to create //////////" << std::endl;
		AForm 	*firstForm;
		firstForm = firstIntern.makeForm("robotomy request", "Bender");
		std::cout << *firstForm;
		delete firstForm;
	}
	catch (std::exception &e)
	{
		std::cerr << "Failed to create a form because : " << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;

	try
	{
		std::cout << "/////////////// RobotomyRequestForm --> Failed to create //////////" << std::endl;
		AForm 	*secondForm;
		secondForm = firstIntern.makeForm("not existing form", "target");
		std::cout << *secondForm;
		delete secondForm;
	}
	catch (std::exception &e)
	{
		std::cerr << "Failed to create a form because : " << e.what() << std::endl;
	}
	std::cout << std::endl;

    return 0;
}

