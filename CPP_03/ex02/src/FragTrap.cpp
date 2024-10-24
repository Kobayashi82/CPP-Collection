/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:22:04 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 19:10:25 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//	Constructors

FragTrap::FragTrap(std::string Name) : ClapTrap(Name) {
	_Hit_Points = 100;
	_Energy_Points = 100;
	_Attack_Damage = 30;
	std::cout << B "FragTrap " Y << _Name << C " constructor called" NC << std::endl;
}

FragTrap::FragTrap(const FragTrap & src) : ClapTrap(src._Name) {
	 *this = src;
	std::cout << B "FragTrap " Y << _Name << C " copy constructor called" NC << std::endl;
}

FragTrap::~FragTrap() { std::cout << B "FragTrap " Y << _Name << C " destructor called" NC << std::endl; }

//	Functions

void FragTrap::attack(const std::string & target) {
	if (_Energy_Points == 0) { std::cout << C "You dont have enough " G "energy points" C " to attack" NC << std::endl; return ; }
	_Energy_Points -= 1;
	std::cout << B "FragTrap " Y << _Name << C " attacks " Y << target << C ", causing " << RD << _Attack_Damage << C " points of damage!" << std::endl;
	std::cout << Y "[" G "Hit Points" Y "]" C " = " NC << _Hit_Points
			  << C "       " Y "[" G "Energy Points" Y "]" C " = " NC << _Energy_Points << std::endl;
}

void FragTrap::highFivesGuys() { std::cout << B "FragTrap " Y << _Name << C " is excited and requests a high five!" NC << std::endl; }

//	Overloads

FragTrap & FragTrap::operator=(const FragTrap & rhs) {
	if (this != &rhs) {
		_Name = rhs._Name;
		_Hit_Points = rhs._Hit_Points;
		_Energy_Points = rhs._Energy_Points;
		_Attack_Damage = rhs._Attack_Damage;
	}
	std::cout << B "FragTrap " Y << _Name << C " assignment operator called" NC << std::endl;
	return (*this);
}
