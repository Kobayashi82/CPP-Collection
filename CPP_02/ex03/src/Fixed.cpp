/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:51 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 18:02:04 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

	//	Constructors

	Fixed::Fixed() { _Fixed_Point = 0 * (1 << _Fractional_Bits); }
	Fixed::Fixed(const int Number) { _Fixed_Point = Number * (1<< _Fractional_Bits); }
	Fixed::Fixed(const float Number) { _Fixed_Point = roundf(Number * (1 << _Fractional_Bits)); }
	Fixed::Fixed(const Fixed & src) { *this = src; }
	Fixed::~Fixed() {}

	//	Functions
	
	int 	Fixed::getRawBits() const { return (_Fixed_Point); }
	void 	Fixed::setRawBits(int const raw) { _Fixed_Point = raw; }
	float	Fixed::toFloat() const { return (static_cast<float>(_Fixed_Point) / (1 << _Fractional_Bits)); }
	int		Fixed::toInt() const { return (_Fixed_Point >> _Fractional_Bits); }

	const Fixed & Fixed::min(const Fixed & Number1, const Fixed & Number2) { if (Number1 < Number2) { return (Number1); } return (Number2); }
	Fixed & Fixed::min(Fixed & Number1, Fixed & Number2) { if (Number1 < Number2) { return (Number1); } return (Number2); }
	const Fixed & Fixed::max(const Fixed & Number1, const Fixed & Number2) { if (Number1 > Number2) { return (Number1); } return (Number2); }
	Fixed & Fixed::max(Fixed & Number1, Fixed & Number2) { if (Number1 > Number2) { return (Number1); } return (Number2); }

	// Overloads
	
	bool Fixed::operator>(const Fixed & rhs) const { return (this->_Fixed_Point > rhs.getRawBits()); }
	bool Fixed::operator<(const Fixed & rhs) const { return (this->_Fixed_Point < rhs.getRawBits()); }
	bool Fixed::operator>=(const Fixed & rhs) const { return (this->_Fixed_Point >= rhs.getRawBits()); }
	bool Fixed::operator<=(const Fixed & rhs) const { return (this->_Fixed_Point <= rhs.getRawBits()); }
	bool Fixed::operator==(const Fixed & rhs) const { return (this->_Fixed_Point == rhs.getRawBits()); }
	bool Fixed::operator!=(const Fixed & rhs) const { return (this->_Fixed_Point != rhs.getRawBits()); }

	Fixed & Fixed::operator=(const Fixed & rhs) { if (this != &rhs) _Fixed_Point = rhs.getRawBits(); return (*this); }
	Fixed Fixed::operator+(const Fixed & rhs) { return (Fixed(toFloat() + rhs.toFloat())); }
	Fixed Fixed::operator-(const Fixed & rhs) { return (Fixed(toFloat() - rhs.toFloat())); }
	Fixed Fixed::operator*(const Fixed & rhs) { return (Fixed(toFloat() * rhs.toFloat())); }
	Fixed Fixed::operator/(const Fixed & rhs) {
		if (rhs.toFloat() == 0.0f) { std::cerr << "Cannot divide by zero" << std::endl; throw std::runtime_error("divide by zero"); }
		return Fixed(this->toFloat() / rhs.toFloat());
	}

	Fixed & Fixed::operator++() { ++_Fixed_Point; return (*this); }
	Fixed & Fixed::operator--() { --_Fixed_Point; return (*this); }
	Fixed Fixed::operator++(int) { Fixed New_Fixed(*this); ++_Fixed_Point; return (New_Fixed); }
	Fixed Fixed::operator--(int) { Fixed New_Fixed(*this); --_Fixed_Point; return (New_Fixed); }

	std::ostream & operator<<(std::ostream & os, const Fixed & rhs) { os << rhs.toFloat(); return (os); }
	