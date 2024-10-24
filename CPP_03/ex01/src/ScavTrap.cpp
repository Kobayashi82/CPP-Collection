/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:22:04 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 19:09:38 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//	Constructors

//	We must call the constructor of the base class in the derived class
ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name) {
	_Hit_Points = 100;
	_Energy_Points = 50;
	_Attack_Damage = 20;
	std::cout << B "ScavTrap " Y << _Name << C " constructor called" NC << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap & src) : ClapTrap(src._Name) {
	*this = src;
	std::cout << B "ScavTrap " Y << _Name << C " copy constructor called" NC << std::endl;
}

//	The base class is destroyed first automatically when destroying a derived class
ScavTrap::~ScavTrap() { std::cout << B "ScavTrap " Y << _Name << C " destructor called" NC << std::endl; }

//	Functions

void ScavTrap::attack(const std::string & target) {
	if (_Energy_Points == 0) { std::cout << C "You dont have enough " G "energy points" C " to attack" NC << std::endl; return ; }
	_Energy_Points -= 1;
	std::cout << B "ScavTrap " Y << _Name << C " attacks " Y << target << C ", causing " << RD << _Attack_Damage << C " points of damage!" << std::endl;
	std::cout << Y "[" G "Hit Points" Y "]" C " = " NC << _Hit_Points
			  << C "       " Y "[" G "Energy Points" Y "]" C " = " NC << _Energy_Points << std::endl;
}

void ScavTrap::guardGate() { std::cout << B "ScavTrap " Y << _Name << C " is now in " Y "Gate Keeper" C " mode" NC << std::endl; }

//	Overloads

ScavTrap & ScavTrap::operator=(const ScavTrap & rhs) {
	if (this != &rhs) {
		_Name = rhs._Name;
		_Hit_Points = rhs._Hit_Points;
		_Energy_Points = rhs._Energy_Points;
		_Attack_Damage = rhs._Attack_Damage;
	}
	std::cout << B "ScavTrap " Y << _Name << C " assignment operator called" NC << std::endl;
	return (*this);
}
