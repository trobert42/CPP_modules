/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:26:32 by trobert           #+#    #+#             */
/*   Updated: 2022/12/16 10:46:06 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	// std::cout << "Constructor called" << std::endl;
	this->_fields[0] = "first name";
	this->_fields[1] = "last name";
	this->_fields[2] = "nickname";
	this->_fields[3] = "phone number";
	this->_fields[4] = "darkest secret";
}

Contact::~Contact(void)
{
	// std::cout << "Destructor called" << std::endl;
}

std::string	Contact::getInfo(int index) const
{
	return (this->_info_contact[index]);
}

void	Contact::setInfo(int index, std::string info_to_add)
{
	this->_info_contact[index] = info_to_add;
}

bool 	Contact::addOneContact(void)
{
	std::string input;

	for (int i(0); i < 5; i++)
	{
		input.erase();
		std::cout << "Enter " << this->_fields[i] << ":" << std::endl;
		while (input[0] == '\0')
		{
			std::getline(std::cin, input);
			if (!std::cin)
				return (false);
		}
		this->setInfo(i, input);
	}
	return (true);
}

void	Contact::printInfoContact(void) const
{
	for (int i(0); i < 5; i++)
		std::cout << this->_fields[i] << ": "<< this->getInfo(i) << std::endl;
}
