/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:43 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 16:20:38 by vzurera-         ###   ########.fr       */
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

	Fixed();
	Fixed(const int Number);
	Fixed(const float Number);
	Fixed(const Fixed & src);
	~Fixed();

	Fixed&operator=(const Fixed & rhs);

	int		getRawBits() const;
	void	setRawBits(int const raw);

	float	toFloat() const;
	int		toInt() const;

};

std::ostream & operator<<(std::ostream & os, const Fixed & rhs);
