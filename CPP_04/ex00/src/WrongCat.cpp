/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:41:47 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 19:17:14 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//	Constructors

WrongCat::WrongCat() : WrongAnimal("Wrong Cat") {
	std::cout << Y << _type << C " constructor called" NC << std::endl;
}
WrongCat::WrongCat(const WrongCat & src) : WrongAnimal(src._type) {
	std::cout << Y << _type << C " copy constructor called" NC << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << Y << _type << C " destructor called" NC << std::endl;
}

//	Functions

void WrongCat::makeSound() const { std::cout << "Quack, quack" << std::endl; }

//	Overloads

WrongCat & WrongCat::operator=(const WrongCat & rhs) {
	std::cout << Y << _type << C " assignment operator called" NC << std::endl;
	if (this != &rhs) WrongAnimal::operator=(rhs);
	return (*this);
}
