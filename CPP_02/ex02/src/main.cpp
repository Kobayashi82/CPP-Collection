/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 17:51:05 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main() {
	std::cout << std::endl << " ======================================" << std::endl << std::endl
			  << BR " In this exercise, we have added all the " G "operators" BR " to the " Y "Fixed Point" BR " class and methods to obtain" << std::endl
			  << " the " G "greater" BR " and " G "lesser" BR " value between two " Y "Fixed Points" BR "." << std::endl << std::endl
			  << " It must be remembered that in the " Y "increment" BR " and " Y "decrement" BR " operators, the value used is the one" << std::endl
			  << " obtained from the " G "fractional" BR " part, that is, " Y "1 / Fractional_Bits" BR "." NC << std::endl << std::endl;
	{

		std::cout <<   " ======================================" << std::endl
				  << G "              DEFAULT TESTS            " NC << std::endl
				  <<   " ======================================" << std::endl << std::endl;
		
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		
		std::cout << C << a << std::endl;
		std::cout << C << ++a << std::endl;
		std::cout << C << a << std::endl;
		std::cout << C << a++ << std::endl;
		std::cout << C << a << std::endl;

		std::cout << b << std::endl;
		
		std::cout << Fixed::max( a, b ) << std::endl;
	} {
		Fixed a(5);
        Fixed b(10);
        Fixed c(5);

		std::cout << std::endl << NC " ======================================" << std::endl
				  			   <<  G "                OWN TESTS              " NC << std::endl
				  			   <<    " ======================================" << std::endl;

		std::cout << std::endl << G " Testing operators with (" C "a " RD "= " Y "5" G ", " C "b " RD "= " Y "10" G ", " C "c " RD "= " Y "5" G ")" << std::endl << std::endl;
		std::cout << NC " ——————————————————————————————————————" << std::endl;
		
try {
        std::cout << std::endl << BR " Testing " C "arithmetic" BR " operators" << std::endl << std::endl;
        std::cout << C " a " RD "+ " C "b " G "=  " Y << a + b << std::endl;
		std::cout << C " a " RD "- " C "b " G "=  " Y << a - b << std::endl;
		std::cout << C " a " RD "* " C "b " G "=  " Y << a * b << std::endl;
		std::cout << C " a " RD "/ " C "b " G "=  " Y << a / b << std::endl;
		std::cout << C " a " RD "/ " C "0 " G "=  " Y << a / 0 << std::endl;
} catch(...) {}

		std::cout << std::endl << std::endl << NC " ——————————————————————————————————————" << std::endl;

        std::cout << std::endl << BR " Testing " C "comparison" BR " operators" << std::endl << std::endl << std::boolalpha;
		std::cout << C " a " RD ">  " C "b " G "=  " Y << (a > b) << std::endl;
		std::cout << C " a " RD "<  " C "b " G "=  " Y << (a < b) << std::endl;
		std::cout << C " a " RD ">= " C "b " G "=  " Y << (a >= b) << std::endl;
		std::cout << C " a " RD "<= " C "b " G "=  " Y << (a <= b) << std::endl;
		std::cout << C " a " RD "== " C "b " G "=  " Y << (a == b) << std::endl;
		std::cout << C " a " RD "!= " C "b " G "=  " Y << (a != b) << std::endl;
		std::cout << C " a " RD "== " C "c " G "=  " Y << (a == c) << std::endl;

		std::cout << std::endl << std::endl << NC " ——————————————————————————————————————" << std::endl;

		std::cout << std::endl << BR " Testing " C "increment" BR "/" C "decrement" BR " operators" << std::endl << std::endl;
        std::cout << C " a" RD "++ " G "=  " Y << a++ << std::endl;
		std::cout << C " a   " G "=  " Y << a << std::endl;
		std::cout << RD " ++" C "a "  G "=  " Y << ++a << std::endl;
		std::cout << C " a   " G "=  " Y << a << std::endl;
        std::cout << C " a" RD "-- " G "=  " Y << a-- << std::endl;
		std::cout << C " a   " G "=  " Y << a << std::endl;
		std::cout << RD " --" C "a "  G "=  " Y << --a << std::endl;
		std::cout << C " a   " G "=  " Y << a << std::endl;

		std::cout << std::endl << std::endl << NC " ——————————————————————————————————————" << std::endl;
		
 		std::cout << std::endl << BR " Testing " C "min" BR "/" C "max" BR " methods" << std::endl << std::endl;
        std::cout << C " The lower value between   " G "a" C " and " G "b" C " is " Y << a.min(a, b) << std::endl;
		std::cout << C " The higher value between  " G "a" C " and " G "b" C " is " Y << a.max(a, b) << std::endl;
		std::cout << C " The lower value between   " G "a" C " and " G "c" C " is " Y << a.min(a, c) << std::endl;
		std::cout << C " The higher value between  " G "b" C " and " G "c" C " is " Y << a.max(b, c) << std::endl;
	}
	std::cout << std::endl << NC " =======================================" << std::endl << std::endl;
}
