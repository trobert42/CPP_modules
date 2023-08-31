/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:07:42 by trobert           #+#    #+#             */
/*   Updated: 2022/12/17 09:18:08 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
	public:
		/*constructor and destructor*/
		Weapon(std::string type);
		~Weapon(void);

		std::string	const & getType(void) const;
		void				setType(std::string const &new_value);


	private:
		std::string _type;
};

#endif