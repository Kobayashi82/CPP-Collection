/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:22:04 by vzurera-          #+#    #+#             */
/*   Updated: 2024/02/26 17:28:31 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//	Constructors

DiamondTrap::DiamondTrap(std::string Name) : ClapTrap(Name + "_clap_name"), ScavTrap(Name), FragTrap(Name), _Name(Name) {
	_Hit_Points = FragTrap::_Hit_Points;
	_Energy_Points = ScavTrap::_Energy_Points;
	_Attack_Damage = FragTrap::_Attack_Damage;
	std::cout << B "DiamondTrap " Y << _Name << C " constructor called" NC << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap & src) : ClapTrap(src._Name + "_clap_name"), ScavTrap(src._Name), FragTrap(src._Name), _Name(src._Name) 
{
	_Hit_Points = src._Hit_Points;
	_Energy_Points = src._Energy_Points; 
	_Attack_Damage = src._Attack_Damage;
	std::cout << B "DiamondTrap " Y << _Name << C " copy constructor called" NC << std::endl;
}

DiamondTrap::~DiamondTrap() { std::cout << B "DiamondTrap " Y << _Name << C " destructor called" NC << std::endl; }

//	Functions

void DiamondTrap::attack(const std::string & target) { ScavTrap::attack(target); }

void DiamondTrap::whoAmI() {
	std::cout << C "ClapTrap name is " Y << ClapTrap::_Name << NC << std::endl;
	std::cout << B "DiamondTrap" C " name is " Y << _Name << NC << std::endl;
}

//	Overloads

DiamondTrap & DiamondTrap::operator=(const DiamondTrap & rhs) {
	if (this != &rhs) {
		_Name = rhs._Name;
		ClapTrap::_Name = _Name + "_clap_name";
		_Hit_Points = rhs._Hit_Points;
		_Energy_Points = rhs._Energy_Points;
		_Attack_Damage = rhs._Attack_Damage;
	}
	std::cout << B "DiamondTrap " Y << _Name << C " assignment operator called" NC << std::endl;
	return (*this);
}
