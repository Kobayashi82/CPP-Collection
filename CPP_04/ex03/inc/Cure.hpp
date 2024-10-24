/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:38:23 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/09 00:25:47 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class Cure : public AMateria {

    public:

        Cure();
        Cure(Cure const & src);
        ~Cure();
        Cure & operator=(Cure const & rhs);

        virtual void use(ICharacter& Target);

        virtual AMateria * clone() const;

};
