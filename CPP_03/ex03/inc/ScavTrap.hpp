/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:22:07 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 19:07:11 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

	public :

		//	Constructors
		
		ScavTrap(std::string Name);
		ScavTrap(const ScavTrap &src);
		virtual ~ScavTrap();

		//	Functions

		void attack(const std::string & target);
		void guardGate();

		// Overloads
		
		ScavTrap& operator=(const ScavTrap& rhs);
	
};

#endif
