/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:26:07 by trobert           #+#    #+#             */
/*   Updated: 2022/12/17 12:06:47 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	// std::cout << "Constructor called" << std::endl;
	this->_index = 0;
	this->_contact_index = 0;
}

PhoneBook::~PhoneBook(void)
{
	// std::cout << "Destructor called" << std::endl;
}

void	PhoneBook::addCommand(void)
{
	Contact	new_contact;

	if (new_contact.addOneContact() == false)
		return ;
	std::cout << "You added one contact to your repertoire" << std::endl;
	this->_tab_contacts[this->_index++] = new_contact;
	this->_contact_index++;
	if (this->_index == _max_contact)
	{
		std::cout << "Repertoire's full, next contact to add will delete the oldest one" << std::endl;
		this->_index = 0;
	}
	return ;
}

void	PhoneBook::printRepertoire(void) const
{
	std::string tmp;
	size_t		count;

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	for(int i(0); i < _max_contact; i++)
	{
		std::cout << "|         " << i << "|";
		for (int j(0); j < _displayed_fields; j++)
		{
			tmp = this->_tab_contacts[i].getInfo(j);
			count = 10 - this->_tab_contacts[i].getInfo(j).length();
			if (this->_tab_contacts[i].getInfo(j).length() > 10)
				tmp.replace(9, this->_tab_contacts[i].getInfo(j).length(), ".\0");
			else
				tmp.insert(0, count, ' ');
			std::cout << tmp << "|";
		}
		std::cout << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
}

void	PhoneBook::searchCommand(void)
{
	std::string input;
	int		 	index;

	if (!this->_contact_index)
	{
		std::cout << "You have no friends :(" << std::endl;
		return ;
	}
	printRepertoire();
	std::cout << "Which one would you like to see the informations ?" << std::endl;
	std::getline(std::cin, input);
	if (!std::cin)
		return ;
	if (input[0] == '\0' || input.length() > 1 || input[0] < '0' || input[0] >= '8')
		std::cout << "Index or format error, please enter a number between 0 and 7 next time" << std::endl;
	else if (std::atoi(input.c_str()) > this->_contact_index - 1)
		std::cout << "Nobody at this index" << std::endl;
	else
	{
		index = std::atoi(input.c_str());
		std::cout 
			<< "You enter the number " << index
			<< ", here's the information about this contact:" << std::endl;
		this->_tab_contacts[index].printInfoContact();
	}
	return ;
}
