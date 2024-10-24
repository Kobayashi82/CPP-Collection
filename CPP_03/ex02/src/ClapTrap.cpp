/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:22:04 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 18:24:22 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//	Constructors

ClapTrap::ClapTrap(std::string Name) : _Name(Name), _Hit_Points(10), _Energy_Points(10), _Attack_Damage(0) {
	std::cout << C "ClapTrap " Y << _Name << C " constructor called" NC << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &src) {
	 *this = src;
	std::cout << C "ClapTrap " Y << _Name << C " copy constructor called" NC << std::endl;
}
ClapTrap::~ClapTrap() {
	std::cout << C "ClapTrap " Y << _Name << C " destructor called" NC << std::endl;
}

//	Functions

void ClapTrap::attack(const std::string & target) {
	if (_Energy_Points == 0) { std::cout << C "You dont have enough " G "energy points" C " to attack" NC << std::endl; return ; }
	_Energy_Points -= 1;
	std::cout << C "ClapTrap " Y << _Name << C " attacks " Y << target << C ", causing " << RD << _Attack_Damage << C " points of damage!" << std::endl;
	std::cout << Y "[" G "Hit Points" Y "]" C " = " NC << _Hit_Points
			  << C "       " Y "[" G "Energy Points" Y "]" C " = " NC << _Energy_Points << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount) {
	if (amount > _Hit_Points) { _Hit_Points = 0; } else { _Hit_Points -= amount; }
	std::cout << C "ClapTrap " Y << _Name << C " has taken " RD << amount << C " points of damage!" << std::endl;
	std::cout << Y "[" G "Hit Points" Y "]" C " = " NC << _Hit_Points
			  << C "       " Y "[" G "Energy Points" Y "]" C " = " NC << _Energy_Points << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount) {
	if (_Energy_Points == 0) { std::cout << C "You dont have enough " G "energy points" C " to repair anything" NC << std::endl; return ; }
	_Energy_Points -= 1; _Hit_Points += amount;
	std::cout << C "ClapTrap " Y << _Name << C " repaired himself " Y << amount << C " hit points!" << std::endl;
	std::cout << Y "[" G "Hit Points" Y "]" C " = " NC << _Hit_Points
			  << C "       " Y "[" G "Energy Points" Y "]" C " = " NC << _Energy_Points << std::endl;
}

//	Overloads

ClapTrap & ClapTrap::operator=(const ClapTrap & rhs) {
	if (this != &rhs) {
		_Name = rhs._Name;
		_Hit_Points = rhs._Hit_Points;
		_Energy_Points = rhs._Energy_Points;
		_Attack_Damage = rhs._Attack_Damage;
	}
	std::cout << C "ClapTrap " Y << _Name << C " assignment operator called" NC << std::endl;
	return (*this);
}
