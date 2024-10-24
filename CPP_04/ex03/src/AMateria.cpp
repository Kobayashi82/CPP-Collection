/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:21:48 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/09 00:26:00 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("") {}
AMateria::AMateria(std::string const & Type) : _type(Type) {}
AMateria::AMateria(AMateria const & src) { *this = src; }
AMateria::~AMateria() {}
AMateria & AMateria::operator=(AMateria const & rhs) { if (this != &rhs) { _type = rhs._type; } return (*this); }

std::string const & AMateria::getType() const { return (_type); }

//	This method is not necessary, as we are not going to use it because both "Ice" and "Cure" use their own 'use' method
//	We could define it as pure virtual in the header
void AMateria::use(ICharacter & Target) { (void) Target; }
