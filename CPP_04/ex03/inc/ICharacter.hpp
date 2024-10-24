/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:18:32 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/09 00:25:55 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include <iostream>

class AMateria;
class ICharacter {

    public:                             //  We don't need to implement the functions in a .cpp file because all the definitions
                                        //  are pure virtual. Except for the destructor, which is implemented directly in the definition
        virtual ~ICharacter() {}

        virtual std::string const & getName() const = 0;
        
        virtual void equip(AMateria * m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter & Target) = 0;

};
