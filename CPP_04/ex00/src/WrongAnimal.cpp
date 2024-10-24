/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:31:14 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 19:17:08 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

//	Constructors

WrongAnimal::WrongAnimal() : _type("Generic") {
	std::cout << C "WrongAnimal " Y << _type << C " constructor called" NC << std::endl;
}
WrongAnimal::WrongAnimal(const std::string Type) : _type(Type) {
	std::cout << C "WrongAnimal " Y << _type << C " constructor called" NC << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal & src) {
	std::cout << C "WrongAnimal " Y << src._type << C " copy constructor called" NC << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal() {
	std::cout << C "WrongAnimal " Y << _type << C " destructor called" NC << std::endl;
}

//	Functions

std::string WrongAnimal::getType() const { return (_type); }
void WrongAnimal::makeSound() const { std::cout << "Wrong Animal Sound, Wrong Animal Sound" << std::endl; }

//	Overloads

WrongAnimal & WrongAnimal::operator=(const WrongAnimal & rhs) {
	std::cout << C "WrongAnimal " Y << _type << C " assignment operator called" NC << std::endl;
	if (this != &rhs) _type = rhs._type;
	return (*this);
}
