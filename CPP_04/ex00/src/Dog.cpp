/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:41:47 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 19:16:59 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//	Constructors

Dog::Dog() : Animal("Dog") {
	std::cout << Y << _type << C " constructor called" NC << std::endl;
}
Dog::Dog(const Dog & src) : Animal(src._type) {
	std::cout << Y << _type << C " copy constructor called" NC << std::endl;
}

Dog::~Dog() {
	std::cout << Y << _type << C " destructor called" NC << std::endl;
}

//	Functions

void Dog::makeSound() const { std::cout << "Woof, woof" << std::endl; }

//	Overloads

Dog & Dog::operator=(const Dog & rhs) {
	std::cout << Y << _type << C " assignment operator called" NC << std::endl;
	if (this != &rhs) Animal::operator=(rhs);
	return (*this);
}
