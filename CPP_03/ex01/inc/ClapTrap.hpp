/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:22:07 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 19:06:00 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Colors.hpp"
#include <iostream>

class ClapTrap {

	protected:

		std::string		_Name;
		unsigned int	_Hit_Points;
		unsigned int	_Energy_Points;
		unsigned int	_Attack_Damage;
	
	public:

		//	Constructors
		
		ClapTrap(std::string Name);
		ClapTrap(const ClapTrap & src);
		~ClapTrap();

		//	Functions

		virtual void attack(const std::string & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		// Overloads
		
		ClapTrap & operator=(const ClapTrap & rhs);
	
};
