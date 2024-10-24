/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:51 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 18:03:32 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//	Constructors

Fixed::Fixed() {
	std::cout << C "Default constructor called" NC << std::endl;
	_Fixed_Point = 0 * (1 << _Fractional_Bits);
}
Fixed::Fixed(const int Number) {
	std::cout << C "Int constructor called" NC << std::endl;
	_Fixed_Point = Number * (1 << _Fractional_Bits);
}
Fixed::Fixed(const float Number) {
	std::cout << C "Float constructor called" NC << std::endl;
	_Fixed_Point = roundf(Number * (1 << _Fractional_Bits));
}
Fixed::Fixed(const Fixed &src) {
	std::cout << C "Copy constructor called" NC << std::endl;
	*this = src;
}
Fixed::~Fixed() { std::cout << C "Destructor called" NC << std::endl; }

//	Functions

int		Fixed::getRawBits() const { return (_Fixed_Point); }
void	Fixed::setRawBits(int const raw) { _Fixed_Point = raw; }

//	Must be casted to float before dividing to prevent losing the fractional part
float	Fixed::toFloat() const { return (static_cast<float>(_Fixed_Point) / (1 << _Fractional_Bits)); }
int		Fixed::toInt() const { return (roundf(static_cast<float>(_Fixed_Point) / (1 << _Fractional_Bits))); }

//	Overloads

Fixed & Fixed::operator=(const Fixed & rhs) {
	std::cout << C "Copy assignment operator called" NC << std::endl;
	if (this != &rhs) _Fixed_Point = rhs.getRawBits();
	return (*this);
}

std::ostream & operator<<(std::ostream & os, const Fixed & rhs) { os << rhs.toFloat(); return (os); }