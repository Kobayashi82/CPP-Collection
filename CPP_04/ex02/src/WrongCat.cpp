/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:41:47 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 19:18:59 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//	Constructors

WrongCat::WrongCat() : WrongAnimal("Wrong Cat"), _Brain(new Brain) {
	std::cout << Y << _type << C " constructor called" NC << std::endl;
}

//	_Brain is a pointer, and therefore it must be dereferenced to create a copy of Brain
WrongCat::WrongCat(const WrongCat & src) : WrongAnimal(src._type), _Brain(new Brain(*(src._Brain))) {
	std::cout << Y << _type << C " copy constructor called" NC << std::endl;
}

//	We must destroy the Brain object when our class is destroyed
WrongCat::~WrongCat() {
	std::cout << Y << _type << C " "; delete _Brain;
	std::cout << Y << _type << C " destructor called" NC << std::endl;
}

//	Functions

void WrongCat::makeSound() const { std::cout << "Quack, quack" << std::endl; }
void WrongCat::setIdea(const int i, std::string idea) { _Brain->ideas[i] = idea; }
std::string WrongCat::getIdea(const int i) const { return (_Brain->ideas[i]); }

//	 Overloads

WrongCat & WrongCat::operator=(const WrongCat & rhs) {
	std::cout << Y << _type << C " assignment operator called" NC << std::endl;
	if (this != &rhs) { WrongAnimal::operator=(rhs); *_Brain = *rhs._Brain; }
	return (*this);
}
