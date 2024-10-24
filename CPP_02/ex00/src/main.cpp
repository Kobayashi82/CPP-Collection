/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 17:22:36 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int	main() {
	std::cout << std::endl << " ======================================" << std::endl << std::endl
			  << BR " Starting from this project, the " B "classes" BR " should be designed using" Y " Orthodox Canonical Form" BR "," << std::endl
			  << " which ensures proper " G "resource" BR " management by implementing:" << std::endl << std::endl
			  << G "   Default Constructor:" C "\t\tInitializes objects without needing specific parameters." << std::endl
			  << G "   Copy Constructor:" C "\t\tCreates a new object as an exact copy of an existing object." << std::endl
			  << G "   Destructor:" C "\t\t\tCleans up and releases resources used by an object." << std::endl
			  << G "   Copy Assignment Operator:" C "\tAssigns the values of one object to another existing object." BR << std::endl << std::endl
			  << " Implementing these " G "four" BR " components ensures that the " B "class" BR " correctly handles object " G "copying" BR << std::endl
			  << " and " G "deletion" BR ", avoiding common issues such as " RD "memory leaks" BR " and " RD "undefined behavior" BR "." << std::endl << std::endl
			  << " In this exercise, a " B "class" BR " has been created that contains the " B "basic structure" BR " for using" << std::endl
			  << " a " Y "Fixed Point" BR " data type." << std::endl << std::endl
			  << " Although in its " C "current state" BR " it only allows changing the " Y "raw" BR " integer value of the " Y "Fixed Point" BR "," << std::endl
			  << " it will serve as a foundation for the next exercise." << std::endl << std::endl
			  << " It's important to note that " G "methods" BR " that " C "read" BR " or " C "modify" BR " the value of a " G "private" BR " variable" << std::endl
			  << " are called " Y "getters" BR " and " Y "setters" BR "." << std::endl << std::endl
			  << " In this case, " Y "getRawBits()" BR " returns the value of " Y "_Fixed_Point" BR ", and similarly, " Y "setRawBits()" BR << std::endl
			  << " assigns it a value." << std::endl << std::endl
			  << " The following messages show the " G "creation" BR ", " G "assignment" BR ", and " G "destruction" BR " of 3 " B "objects" BR " of" << std::endl
			  << " type " Y "Fixed Point" BR "." << std::endl << std::endl
			  << " These messages are the same as those indicated in the " B "subject" BR "." NC << std::endl << std::endl;
	{
		std::cout <<   " ======================================" << std::endl
				  << G "              DEFAULT TESTS            " NC << std::endl
				  <<   " ======================================" << std::endl << std::endl;

		Fixed a;
		Fixed b(a);
		Fixed c;

		c = b;
		
		std::cout << a.getRawBits() << NC << std::endl;
		std::cout << b.getRawBits() << NC  << std::endl;
		std::cout << c.getRawBits() << NC  << std::endl;
	}
	std::cout << std::endl << " =======================================" << std::endl << std::endl;
}
