/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:44:02 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/09 00:25:53 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class Ice : public AMateria {

    public:

        Ice();
        Ice(Ice const & src);
        ~Ice();
        Ice & operator=(Ice const & rhs);

        virtual void use(ICharacter & Target);
        
        virtual AMateria * clone() const;
        
};
