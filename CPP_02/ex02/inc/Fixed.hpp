/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:43 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 18:02:42 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Colors.hpp"
# include <iostream>
# include <cmath>

class Fixed {

private:

	int					_Fixed_Point;
	static const int	_Fractional_Bits = 8;

public:

	//	Constructors
	
	Fixed();
	Fixed(const int Number);
	Fixed(const float Number);
	Fixed(const Fixed & src);
	~Fixed();

	//	Functions

	int		getRawBits() const;
	void	setRawBits(int const raw);

	float	toFloat() const;
	int		toInt() const;

	static const Fixed & min(const Fixed & Number1, const Fixed & Number2);
	static Fixed & min(Fixed & Number1, Fixed & Number2);
	static const Fixed & max(const Fixed & Number1, const Fixed & Number2);
	static Fixed & max(Fixed & Number1, Fixed & Number2);

	// Overloads
	
	bool operator>(const Fixed & rhs) const;
	bool operator<(const Fixed & rhs) const;
	bool operator>=(const Fixed & rhs) const;
	bool operator<=(const Fixed & rhs) const;
	bool operator==(const Fixed & rhs) const;
	bool operator!=(const Fixed & rhs) const;

	Fixed & operator=(const Fixed & rhs);
	Fixed operator+(const Fixed & rhs);
	Fixed operator-(const Fixed & rhs);
	Fixed operator*(const Fixed & rhs);
	Fixed operator/(const Fixed & rhs);

	Fixed & operator++();
	Fixed & operator--();
	Fixed operator++(int);
	Fixed operator--(int);

};

std::ostream & operator<<(std::ostream & os, const Fixed & rhs);