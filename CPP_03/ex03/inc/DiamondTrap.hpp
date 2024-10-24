/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:22:07 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 19:11:40 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

	private:

		std::string _Name;

	public:

		//	Constructors
		
		DiamondTrap(std::string Name);
		DiamondTrap(const DiamondTrap & src);
		~DiamondTrap();

		//	Functions

		void attack(const std::string & target);
		void whoAmI();

		// Overloads
		
		DiamondTrap & operator=(const DiamondTrap & rhs);

};
