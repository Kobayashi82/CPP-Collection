/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:41:47 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 19:18:44 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//	Constructors

Dog::Dog() : Animal("Dog"), _Brain(new Brain) {
	std::cout << Y << _type << C " constructor called" NC << std::endl;
}

//	_Brain is a pointer, and therefore it must be dereferenced to create a copy of Brain
Dog::Dog(const Dog & src) : Animal(src._type), _Brain(new Brain(*(src._Brain))) {
	std::cout << Y << _type << C " copy constructor called" NC << std::endl;
}

//	We must destroy the Brain object when our class is destroyed
Dog::~Dog() {
	std::cout << Y << _type << C " "; delete _Brain;
	std::cout << Y << _type << C " destructor called" NC << std::endl;
}

//	Functions

void Dog::makeSound() const { std::cout << "Woof, woof" << std::endl; }
void Dog::setIdea(const int i, std::string idea) { _Brain->ideas[i] = idea; }
std::string Dog::getIdea(const int i) const { return (_Brain->ideas[i]); }

//	Overloads

//	We must perform a deep copy, so we call the assignment operator of Animal and Brain,
//	which handle their respective copies.
//	Although we could assign '_type = rhs._type', it is preferable to call the copy assignment of Animal
Dog & Dog::operator=(const Dog & rhs) {
	std::cout << Y << _type << C " assignment operator called" NC << std::endl;
	if (this != &rhs) { Animal::operator=(rhs); *_Brain = *rhs._Brain; }
	return (*this);
}
