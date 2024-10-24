/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:25:45 by vzurera-          #+#    #+#             */
/*   Updated: 2024/02/22 18:34:27 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string Name) : _Name(Name), _Weapon(0) {
}

HumanB::~HumanB() {

}

void HumanB::setWeapon(Weapon &New_Weapon) {
	_Weapon = &New_Weapon;
}

void HumanB::attack() {
	if (_Weapon == 0 || _Weapon->getType().empty())
		std::cout << "	" Y UN << _Name << NC C " doesn't have any weapon" << NC << std::endl;	
	else
		std::cout << "	" Y UN << _Name << NC C " attacks with their " RD UN << _Weapon->getType() << NC << std::endl;
}