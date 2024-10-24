/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:38:00 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/09 00:26:07 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}
//	We don't need to perform any copy because _type will always be "ice", but we can instantiate the 
//	base class with "src", which will be of type "ice", or directly use AMateria("ice")
Ice::Ice(Ice const & src) : AMateria(src) {}
Ice::~Ice() {}
//	We call the copy operator of the base class. No need to copy _type
Ice & Ice::operator=(const Ice & rhs) { if (this != &rhs) { AMateria::operator=(rhs); } return (*this); }

void Ice::use(ICharacter & Target) { std::cout << RD "*" C " shoots an " B "ice" C " bolt at " Y << Target.getName() << RD " *" NC << std::endl; }

//	As a new instance of Ice will be of type "ice", we only need to return a new instance, not really clone anything
AMateria * Ice::clone() const { return (new Ice()); }
