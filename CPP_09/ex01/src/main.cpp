/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 21:17:24 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "RPN.hpp"
#include <iostream>


int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout  << std::endl << RD "            Incorrect number of arguments" << std::endl << std::endl;
		std::cout << C "\tUsage: " Y "./RPN [" G "Mathematical Expression" Y "]" NC << std::endl << std::endl;
		return (0);
    }
	std::cout << std::endl << " ======================================" << std::endl << std::endl
			  << BR " In this exercise we have to create a "B "program" BR " named " Y "RPN" BR " that can evaluate " G "mathematical expressions" BR << std::endl
			  << " written in " Y "Reverse Polish Notation (RPN)" BR "." << std::endl << std::endl
			  << Y " RPN" BR " is a " G "mathematical notation" BR " where every " C "operator" BR " follows all of its " C "operands" BR "." << std::endl << std::endl
			  << " For example, instead of writing " Y "3 + 4" BR ", you would write " Y "3 4 +" BR "." << std::endl << std::endl
			  << " The program will take an " G "expression" BR " as argument where the " C "operands" BR " will range from " B "0" BR " to " B "9" BR "." << std::endl << std::endl
			  << " The program must read this " G "expression" BR ", process it, and then output the correct " G "result" BR "." << std::endl << std::endl
			  << " If anything goes " RD "wrong" BR " during the execution, such as an " RD "invalid expression" BR " or a " RD "division by zero" BR "," << std::endl
			  << " the program should print an " RD "error message" BR "." << std::endl << std::endl
			  << " To manage the processing of the " Y "RPN" G " expressions" BR ", we are required to use at least one " Y "container" BR "," << std::endl
			  << " in this case a " Y "stack container" NC "." << std::endl << std::endl
			  << " ——————————————————————————————————————" << std::endl << std::endl
			  << C " Below are some mathematical expressions you can try:" << std::endl << std::endl
			  << G " 45 " B " ./RPN \"" Y " 2 3 + 4 5 + * " B "\"" << std::endl
			  << C "     Infix  " RD "(2 + 3) * (4 + 5)" << std::endl << std::endl

			  << G " 17 " B " ./RPN \"" Y " 8 2 / 3 * 4 1 + + " B "\"" << std::endl
			  << C "     Infix  " RD "((8 / 2) * 3) + (4 + 1)" << std::endl << std::endl

			  << G " -10" B " ./RPN \"" Y " 5 5 + 6 4 + - 7 3 + - " B "\"" << std::endl
			  << C "     Infix  " RD "(((5 + 5) - (6 + 4)) - (7 + 3)" << std::endl << std::endl

			  << G " 170" B " ./RPN \"" Y " 4 5 * 3 2 * 6 7 * 8 9 * + + + 2 2 * 1 1 * + + 3 3 * 4 4 * + + " B "\"" NC << std::endl
			  << C "     Infix  " RD "(((4 * 5) + (3 * 2) + (6 * 7) + (8 * 9)) + (2 * 2) + (1 * 1)) + (3 * 3) + (4 * 4)" NC << std::endl << std::endl;

	{
		std::cout << " ======================================" << std::endl << std::endl;

		std::string Expression; for (int i = 1; i < argc; ++i) { Expression += std::string(argv[i]) + " "; }				//	Join args into a single string separate by space
		
		RPN(Expression);
	}
	std::cout  << std::endl << " =======================================" << std::endl << std::endl;
}
