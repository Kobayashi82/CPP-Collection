/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:16:16 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/09 00:25:43 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Colors.hpp"
#include "Floor.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {

    private:

        std::string _name;
        AMateria *  _inventory[4];

        Character();

    public:

        Character(std::string const & Name);
        Character(Character const & src);
        ~Character();
        Character & operator=(Character const & rhs);

        std::string const & getName() const;
        
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter & Target);

};
