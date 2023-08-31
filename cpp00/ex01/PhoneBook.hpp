/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:26:18 by trobert           #+#    #+#             */
/*   Updated: 2022/12/16 10:48:59 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

class PhoneBook
{
	public:
		/*constructor and destructor*/
		PhoneBook(void);
		~PhoneBook(void);

		/*public fonctions only for objects from the object phonebook class*/
		void	addCommand(void);
		void	searchCommand(void);
		void	printRepertoire(void) const;


	private:
		static int const	_max_contact = 8;
		static int const	_displayed_fields = 3;
		Contact				_tab_contacts[_max_contact];
		int					_index;
		int					_contact_index;
};

#endif
