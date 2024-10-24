/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:38:46 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/09 00:26:10 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

//  Initialize _materias with NULL
MateriaSource::MateriaSource() { for (int i = 0; i < 4; i++) _materias[i] = NULL; }
//  Call the copy operator
MateriaSource::MateriaSource(MateriaSource const & src) { *this = src; }
//  Destroy the objects in _materias in the destructor
MateriaSource::~MateriaSource() { for (int i = 0; i < 4; i++) if (_materias[i]) delete _materias[i]; }

//  Free the current _materias and perform a deep copy of the new _materias
MateriaSource & MateriaSource::operator=(MateriaSource const & rhs) {
    if (this != &rhs) {
        for (int i = 0; i < 4; i++) {
            if (_materias[i]) delete _materias[i];
            _materias[i] = rhs._materias[i];
        }
    } return (*this);
}

//  Add a new materia to _materias
void MateriaSource::learnMateria(AMateria * m) {
    if (!m) return ;
    for (int i = 0; i < 4; i++) 
        if (_materias[i] == NULL) { _materias[i] = m; return ; }
    delete m;
}

//  If the Type is in _materias return a copy
AMateria * MateriaSource::createMateria(std::string const & Type) {
    for (int i = 0; i < 4; i++)
        if (_materias[i] && _materias[i]->getType() == Type) return (_materias[i]->clone());
    return (NULL);
}
