/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:22:07 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 19:07:34 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	public :

		//	Constructors
		
		ScavTrap(std::string Name);
		ScavTrap(const ScavTrap & src);
		~ScavTrap();

		//	Functions

		void attack(const std::string & target);
		void guardGate();

		// Overloads
		
		ScavTrap & operator=(const ScavTrap & rhs);
	
};
