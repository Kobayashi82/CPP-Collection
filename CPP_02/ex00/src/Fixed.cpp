/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:51 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 17:37:29 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//	Constructors

Fixed::Fixed() : _Fixed_Point(0) { std::cout << C "Default constructor called" NC << std::endl; }
Fixed::Fixed(const Fixed & src) { std::cout << C "Copy constructor called" NC << std::endl; *this = src; }
Fixed::~Fixed() { std::cout << C "Destructor called" NC << std::endl; }

//	Functions

int Fixed::getRawBits() const { std::cout << Y "getRawBits()" C " member function called" G << std::endl; return (_Fixed_Point); }
void Fixed::setRawBits(int const raw) { _Fixed_Point = raw; }

//	Overloads

Fixed & Fixed::operator=(const Fixed & rhs) {
	std::cout << C "Copy assignment operator called" NC << std::endl;
	if (this != &rhs) _Fixed_Point = rhs.getRawBits();
	return (*this);
}
