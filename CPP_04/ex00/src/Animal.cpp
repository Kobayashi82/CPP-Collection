/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:31:14 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 19:16:43 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//	Constructors

Animal::Animal() : _type("Generic") {
	std::cout << C "Animal " Y << _type << C " constructor called" NC << std::endl;
}
Animal::Animal(const std::string Type) : _type(Type) {
	std::cout << C "Animal " Y << _type << C " constructor called" NC << std::endl;
}
Animal::Animal(const Animal & src) {
	std::cout << C "Animal " Y << src._type << C " copy constructor called" NC << std::endl;
	*this = src;
}

Animal::~Animal() {
	std::cout << C "Animal " Y << _type << C " destructor called" NC << std::endl;
}

//	Functions

std::string Animal::getType() const { return (_type); }
void Animal::makeSound() const { std::cout << "Animal Sound, Animal Sound" << std::endl; }

//	Overloads

Animal & Animal::operator=(const Animal & rhs) {
	std::cout << C "Animal " Y << _type << C " assignment operator called" NC << std::endl;
	if (this != &rhs) _type = rhs._type;
	return (*this);
}
