/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:41:47 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 19:16:52 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//	Constructors

Cat::Cat() : Animal("Cat") {
	std::cout << Y << _type << C " constructor called" NC << std::endl;
}
Cat::Cat(const Cat & src) : Animal(src._type) {
	std::cout << Y << _type << C " copy constructor called" NC << std::endl;
}

Cat::~Cat() {
	std::cout << Y << _type << C " destructor called" NC << std::endl;
}

//	Functions

void Cat::makeSound() const { std::cout << "Meow, meow" << std::endl; }

//	Overloads

Cat & Cat::operator=(const Cat & rhs) {
	std::cout << Y << _type << C " assignment operator called" NC << std::endl;
	if (this != &rhs) Animal::operator=(rhs);
	return (*this);
}
