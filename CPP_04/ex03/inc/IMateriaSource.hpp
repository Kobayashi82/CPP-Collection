/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:19:40 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/09 00:25:57 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class IMateriaSource {

    public:                             //  We don't need to implement the functions in a .cpp file because all the definitions
                                        //  are pure virtual. Except for the destructor, which is implemented directly in the definition
        virtual ~IMateriaSource() {}

        virtual void learnMateria(AMateria * m) = 0;
        virtual AMateria * createMateria(std::string const & Type) = 0;

};
