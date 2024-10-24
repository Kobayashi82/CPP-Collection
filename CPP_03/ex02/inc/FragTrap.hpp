/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:22:07 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 19:07:27 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

	public :

		//	Constructors
		
		FragTrap(std::string Name);
		FragTrap(const FragTrap & src);
		~FragTrap();

		//	Functions

		void attack(const std::string & target);
		void highFivesGuys(void);

		// Overloads
		
		FragTrap & operator=(const FragTrap & rhs);
	
};
