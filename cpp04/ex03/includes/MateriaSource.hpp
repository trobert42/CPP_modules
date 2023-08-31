/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:16:30 by trobert           #+#    #+#             */
/*   Updated: 2022/12/27 17:14:10 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
	
		MateriaSource(MateriaSource const & cpy);
	
		virtual ~MateriaSource(void);

		MateriaSource & operator=(MateriaSource const & rhs);

		virtual void 		learnMateria(AMateria*);
		virtual AMateria* 	createMateria(std::string const & type);
		virtual void		printInventory(void) const;


	private:
		static const int	MAX_MATERIA = 4; 
		AMateria			*_inventory[MAX_MATERIA];
		
};

#endif