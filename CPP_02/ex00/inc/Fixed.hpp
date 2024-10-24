/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:43 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 16:03:34 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Colors.hpp"
#include <iostream>

class Fixed {

private:

	int					_Fixed_Point;
	static const int	_Fractional_Bits = 8;						//	static means that this variable is not associated with any instance of the class and is shared among all instances.

public:

	Fixed();
	Fixed(const Fixed & src);
	~Fixed();

	Fixed & operator=(const Fixed & rhs);

	int		getRawBits() const;
	void	setRawBits(int const raw);

};
