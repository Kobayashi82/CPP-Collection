/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:41:47 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 19:18:37 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//	Constructors

Cat::Cat() : Animal("Cat"), _Brain(new Brain) {
	std::cout << Y << _type << C " constructor called" NC << std::endl;
}

//	_Brain is a pointer, and therefore it must be dereferenced to create a copy of Brain
Cat::Cat(const Cat & src) : Animal(src._type), _Brain(new Brain(*(src._Brain))) {
	std::cout << Y << _type << C " copy constructor called" NC << std::endl;
}

//	We must destroy the Brain object when our class is destroyed
Cat::~Cat() {
	std::cout << Y << _type << C " "; delete _Brain;
	std::cout << Y << _type << C " destructor called" NC << std::endl;
}

//	Functions

void Cat::makeSound() const { std::cout << "Meow, meow" << std::endl; }
void Cat::setIdea(const int i, std::string idea) { _Brain->ideas[i] = idea; }
std::string Cat::getIdea(const int i) const { return (_Brain->ideas[i]); }

//	Overloads

Cat & Cat::operator=(const Cat & rhs) {
	std::cout << Y << _type << C " assignment operator called" NC << std::endl;
	if (this != &rhs) { Animal::operator=(rhs); *_Brain = *rhs._Brain; }
	return (*this);
}
