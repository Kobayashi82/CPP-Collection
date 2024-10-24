/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:25:45 by vzurera-          #+#    #+#             */
/*   Updated: 2024/02/22 18:28:54 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string Name) {
	_Type = Name;
}

Weapon::~Weapon() {

}

std::string const &Weapon::getType() const {
	return (_Type);
}

void Weapon::setType(std::string Type) {
	_Type = Type;
}