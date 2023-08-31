/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:26:28 by trobert           #+#    #+#             */
/*   Updated: 2022/12/16 10:45:39 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
	public:
		/*constructor and destructor*/
		Contact(void);
		~Contact(void);
		
		/*getter and setter*/
		std::string	getInfo(int index) const;
		void		setInfo(int index, std::string info_to_add);

		/*public fonctions only for objects from the class contact*/
		bool		addOneContact(void);
		void		printInfoContact(void) const;


	private:
		std::string _info_contact[5];
		std::string _fields[5];
};

#endif
