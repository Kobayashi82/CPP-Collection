/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 17:43:53 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main() {
	std::cout << std::endl << " ======================================" << std::endl << std::endl
			  << BR " A " Y "Fixed Point" BR " represents " G "real" BR " numbers by allocating " G "fixed bits" BR " for " G "integer" BR " and " G "fractional" BR " parts." << std::endl << std::endl
			  << " Ideal for precision in systems with " RD "limited" BR " resources or where " RD "performance" BR " is critical." << std::endl << std::endl
			  
			  << " To obtain the " C "scale" BR " number for the " G "fractional" BR " parts, we use " Y "1 << Fractional_Bits" BR " being" << std::endl
			  << Y " Fractional_Bits" BR " = " B "8" BR "." << std::endl << std::endl

			  << " This is equivalent to " Y "2^Fractional_Bits" BR " or " Y "2 x 2 x 2 x 2 x 2 x 2 x 2 x 2" BR "." << std::endl
			  << " Using the " C "bit shift operation" BR " to calculate this number is faster." << std::endl << std::endl

			  << " By multiplying a number by the " G "fractional" BR " number used, we get an integer that contains both the" << std::endl
			  << G " non-decimal" BR " and the " G "decimal" BR " part." << std::endl << std::endl

			  << " Example: " C "42.42 * (1 << 8)" BR " = " C "42.42 * 256" BR " = " C "10859.52 " BR "rounded to " G "10860" BR "." << std::endl << std::endl
			  << " This number is stored in an " Y "integer" BR " variable. When we need to obtain its " Y "decimal" BR " value again, we" << std::endl
			  << " can do the opposite." << std::endl << std::endl
			  << " Example: " C "10860 / (1 << 8)" BR " = " C "10860 / 256" BR " = " C "42.421875 " BR "rounded to " G "42.4219" BR "." << std::endl << std::endl

			  << " Something to consider is that the fraction between decimals is " Y "1 / (1 << Fractional_Bits)" BR " or" << std::endl
			  << Y " 1 / 256" BR " in this case." << std::endl << std::endl
			  
			  << " This means that each unit in the " Y "Fixed Point" BR " representation increases the " G "real" BR " value" << std::endl
			  << " by " Y "1 / 256" BR " or " Y "0.00390625" BR "." << std::endl << std::endl

			  << " Example: " C "5 * 256" BR " = " C "1280" BR ", if we increase by one unit, we would have " C "1281" BR "." << std::endl
			  << " Converting it to the " G "real" BR " number as " Y "float" BR " we would have a value of " C "5.00390625" BR "." << std::endl << std::endl

			  << " Therefore, the " C "higher" BR " the value of " Y "Fractional_Bits" BR ", the " C "greater" BR " the precision and length of" << std::endl
			  << " the decimal part." << std::endl << std::endl
			  << " But it also reduces the " G "maximum" BR " range of the " G "integer" BR " part." << std::endl << std::endl

			  << " This way of dealing with " G "floating" BR " point numbers using " Y "Fixed Point" BR " integers improves system" << std::endl
			  << " performance." NC << std::endl << std::endl;
	{
		std::cout <<   " ======================================" << std::endl
				  << G "                OWN TESTS              " NC << std::endl
				  <<   " ======================================" << std::endl << std::endl;

		std::cout << G " Create a " Y "Fixed Point (a)" G " using the " Y "DEFAULT" G " constructor \t\t" W " Fixed a;" << std::endl << std::endl;
		Fixed a;
		std::cout << std::endl << G " Create a " Y "Fixed Point (b)" G " using the " Y "INT" G " constructor \t\t\t" W " Fixed " B "const " W "b" B "(" Y "10" B ")" W ";" << std::endl << std::endl;
		Fixed const b(10);
		std::cout << std::endl << G " Create a " Y "Fixed Point (c)" G " using the " Y "FLOAT" G " constructor \t\t\t" W " Fixed " B "const " W "c" B "(" Y "42.42f" B ")" W ";" << std::endl << std::endl;
		Fixed const c(42.42f);
		std::cout << std::endl << G " Create a " Y "Fixed Point (d)" G " using the " Y "COPY" G " constructor \t\t\t" W " Fixed " B "const " W "d" B "(" W "b" B ")" W ";" << std::endl << std::endl;
		Fixed const d(b);
		std::cout << std::endl << G " Assign a new object to " Y "Fixed Point (a)" G " using the " Y "ASSIGN" G " operator \t" W " a = Fixed" B "(" Y "1234.6721f" B ")" W ";" NC << std::endl << std::endl;
		a = Fixed(1234.6721f);
		std::cout << std::endl << std::endl << " ——————————————————————————————————————" NC << std::endl << std::endl;

		std::cout << G " The current values of the " Y "Fixed Points" G " as float and the " Y "raw" G " values:" << std::endl << std::endl;

		std::cout << Y " a" C " is " RD << a << G "\t(" M << a.getRawBits() << G ")" NC << std::endl;
		std::cout << Y " b" C " is " RD << b << G "\t(" M << b.getRawBits() << G ")" NC << std::endl;
		std::cout << Y " c" C " is " RD << c.toFloat() << G "\t(" M << c.getRawBits() << G ")" NC << std::endl;
		std::cout << Y " d" C " is " RD << d.toFloat() << G "\t(" M << d.getRawBits() << G ")" NC << std::endl;

		std::cout << std::endl << G " The current values of the " Y "Fixed Points" G " as integer and the " Y "raw" G " values:" << std::endl << std::endl;

		std::cout << Y " a " C "is " RD << a.toInt() << G "\t(" M << a.getRawBits() << G ")" NC << std::endl;
		std::cout << Y " b " C "is " RD << b.toInt() << G "\t(" M << b.getRawBits() << G ")" NC << std::endl;
		std::cout << Y " c " C "is " RD << c.toInt() << G "\t(" M << c.getRawBits() << G ")" NC << std::endl;
		std::cout << Y " d " C "is " RD << d.toInt() << G "\t(" M << d.getRawBits() << G ")" NC << std::endl;
		
		std::cout << std::endl << std::endl << " ——————————————————————————————————————" NC << std::endl;
		std::cout << std::endl << G " We can destroy de objects now" << std::endl << std::endl;
	}
	std::cout << std::endl << " =======================================" << std::endl << std::endl;
}
