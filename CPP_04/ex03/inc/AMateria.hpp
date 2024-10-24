/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:13:58 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/09 00:25:41 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Colors.hpp"
#include "ICharacter.hpp"
#include <iostream>

class ICharacter;
class AMateria {

    protected:

        std::string _type;

    public:

        AMateria();
        AMateria(std::string const & Type);
        AMateria(AMateria const & src);
        virtual ~AMateria();
        AMateria & operator=(AMateria const & rhs);
        
        std::string const & getType() const;

        virtual void use(ICharacter & Target);  // We could define it as pure virtual...
        
        virtual AMateria * clone() const = 0;

};
