/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:38:15 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/09 00:41:48 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

//  Initialize _inventory with NULL
Character::Character(std::string const & Name) : _name(Name) { for (int i = 0; i < 4; i++) _inventory[i] = NULL; }
//  Call the copy operator
Character::Character(Character const & src) { *this = src; }
//  Destroy the objects in _inventory in the destructor
Character::~Character() { for (int i = 0; i < 4; i++) if (_inventory[i]) delete _inventory[i]; }

//  Free the current _inventory and perform a deep copy of the new _inventory and _name
Character & Character::operator=(Character const & rhs) {
    if (this != &rhs) { _name = rhs._name;
        for (int i = 0; i < 4; i++) {
            if (_inventory[i]) delete _inventory[i];
            _inventory[i] = rhs._inventory[i];
        }
    } return (*this);
}

std::string const & Character::getName() const { return (_name); }

//  Here we equip a materia on our character. But if all 4 slots are occupied, it drops it to the floor
//  Floor::add() is an array that contains all the materials that are on the ground
void Character::equip(AMateria * m) {
    if (!m) return ;
    for (int i = 0; i < 4; i++) {
        if (_inventory[i] == NULL) { _inventory[i] = m;
            std::cout << Y << _name << C " equipped " G << m->getType() << NC << std::endl; return ;
        }
    }
    Floor::add(m);
    std::cout << Y << _name << C " can't equip " G << m->getType() << C " and drop it on the " B "floor" NC << std::endl;
}

//  When we drop a material on the ground, we add it to the floor array
void    Character::unequip(int idx) {
    if (idx < 0 || idx > 3) return ;
    if (_inventory[idx]) {
        std::cout << Y << _name << C " unequipped " G << _inventory[idx]->getType() << C " and drop it on the " B "floor" NC << std::endl;
        Floor::add(_inventory[idx]); _inventory[idx] = NULL;
    } else
        std::cout << Y << _name << C " can't unequip whatever you tried to unequip" NC << std::endl;
}

void    Character::use(int idx, ICharacter & Target) {
    if (idx < 0 || idx > 3) return ;
    if (_inventory[idx]) {
        std::cout << Y << _name << C " uses " G << _inventory[idx]->getType() << C " on " Y << Target.getName() << NC << std::endl;
        _inventory[idx]->use(Target);
    } else
        std::cout << Y << _name << C " can't use whatever you want on " Y << Target.getName() << NC << std::endl;
}
