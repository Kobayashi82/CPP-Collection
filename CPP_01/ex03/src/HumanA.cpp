/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:25:45 by vzurera-          #+#    #+#             */
/*   Updated: 2024/02/22 18:33:22 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"

HumanA::HumanA(std::string Name, Weapon &Weapon) : _Name(Name), _Weapon(Weapon) {
}

HumanA::~HumanA() {

}

void HumanA::attack() {
	if (_Weapon.getType().empty())
		std::cout << "	" Y UN << _Name << NC C " doesn't have any weapon" << NC << std::endl;	
	else
		std::cout << "	" Y UN << _Name << NC C " attacks with their " RD UN << _Weapon.getType() << NC << std::endl;
}