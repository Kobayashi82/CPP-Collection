/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:38:09 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/09 00:26:04 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}
//	We don't need to perform any copy because _type will always be "cure", but we can instantiate the 
//	base class with "src", which will be of type "cure", or directly use AMateria("cure")
Cure::Cure(Cure const & src) { *this = src; }
Cure::~Cure() {}
//	We call the copy operator of the base class. No need to copy _type
Cure & Cure::operator=(const Cure & rhs) { if (this != &rhs) { AMateria::operator=(rhs); } return (*this); }

void Cure::use(ICharacter& Target) { std::cout << RD "* " G "heals " Y << Target.getName() << "'s " C "wounds " RD "*" NC << std::endl; }

//	As a new instance of Ice will be of type "ice", we only need to return a new instance, not really clone anything
AMateria * Cure::clone() const { return (new Cure()); }
