/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 20:48:38 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "easyfind.hpp"
#include <iostream>
#include <limits>
#include <vector>
#include <list>

//	Validate input
static std::string isValid(std::string literal) {
	std::size_t k = 0;
    std::size_t j = literal.length();
    while (k < j && std::isspace(static_cast<unsigned char>(literal[k]))) ++k;
    while (j > k && std::isspace(static_cast<unsigned char>(literal[j - 1]))) --j;
    literal = literal.substr(k, j - k);
    if (literal.empty()) throw std::runtime_error("Invalid input");
    int DecimalPoint = 0;
    for (size_t i = 0; i < literal.length(); ++i) {
		if (i == 0 && (literal[i] == '+' || literal[i] == '-')) i++;
        if (literal[i] == '.')
			if (DecimalPoint) throw std::runtime_error("Invalid input"); else DecimalPoint = 1;
        else if (i == literal.length() - 1 && literal[i] == 'f') return (literal);
		else if (!std::isdigit(literal[i])) throw std::runtime_error("Invalid input");
    }
    return (literal);
}

int main(int argc, char **argv) {
	if ( argc != 2 ) {
		std::cout  << std::endl << RD "      Incorrect number of arguments" << std::endl << std::endl;
		std::cout << C "\tUsage: " Y "./Easy_Find [" G "Number" Y "]" NC << std::endl << std::endl;
		return (0);
    }

	std::cout << std::endl << " ======================================" << std::endl << std::endl
			  << G " Algorithms" BR ", " G "vectors" BR ", " G "lists" BR "... we can finally use them, and they are a great help " << std::endl
			  << " in managing groups of data like " B "arrays" BR "." << std::endl << std::endl
			  << " We can perform " C "search" BR ", " C "replacement" BR " and " C "sorting" BR " operations efficiently and quickly." << std::endl << std::endl
			  << " In this exercise, we have created a " Y "template" BR " that allows us to search in different " Y "types" BR " of" << std::endl
			  << " containers and will return a " B "boolean" BR " value with the result." << std::endl << std::endl
			  << " For the tests, I have created two containers with different numbers." << std::endl << std::endl
			  << " When you run the program, you give it a number. First, we check if the number is " G "valid" BR ", then" << std::endl
			  << " we look for it in the containers." << std::endl << std::endl
			  << " We must not forget that the " Y "template" BR " used only works with " G "sequential" BR " containers, since" << std::endl
			  << G " associative" BR " containers work with " C "keys-values" BR"." NC << std::endl << std::endl;
	{

		std::cout <<   " ======================================" << std::endl
				  << G "               FIND TESTS              " NC << std::endl
				  <<   " ======================================" << std::endl << std::endl;

		try {
			
			//	Validate the input
			long L_Number = std::atol(isValid(argv[1]).c_str());
			if (L_Number > std::numeric_limits<int>::max() || L_Number < std::numeric_limits<int>::min()) throw std::runtime_error("Invalid input");
			int Number = static_cast <int> (L_Number);

			//	Create the arrays
			int Array1[] = {12, 47, 55, 23, 78, 91, 86, 4, 33, 67, 42, 20, 98, 34, 76, 59, 82, -29, 11, 60};
			int Array2[] = {88, 26, 64, 42, 7, 95, 72, 18, 39, 50, 3, 85, 92, 14, -37, 9, 70, 61, 44, 99};

			//	To create the containers, we pass the Array and the location of the last index as arguments.
			//	The number of indices is added to the memory address where the Array is located.
			//	The number of indices is obtained dividing the size of the Array by the size of the data type.
			std::vector <int> vect(Array1, Array1 + sizeof(Array1) / sizeof(int));
			std::list <int> list(Array2, Array2 + sizeof(Array2) / sizeof(int));

			//	Vector
			std::cout << G " Vector:\t" B; printArray(Array1, sizeof(Array1) / sizeof(int), Number); std::cout << NC << std::endl << std::endl;
			
			if (easyFind(vect, Number))
				std::cout << C " The number " Y << Number <<  C " is in " G "Vector" NC << std::endl << std::endl;
			else
				std::cout << C " The number " Y << Number <<  C " is " RD "not" C " in " G "Vector" NC << std::endl << std::endl << std::endl;
			std::cout << std::endl << NC " ——————————————————————————————————————" << std::endl << std::endl;
			
			//	List
			std::cout << G " List:  \t" B; printArray(Array2, sizeof(Array2) / sizeof(int), Number); std::cout << NC << std::endl << std::endl;
			if (easyFind(list, Number))
				std::cout << C " The number " Y << Number <<  C " is in " G "List" NC << std::endl;
			else
				std::cout << C " The number " Y << Number <<  C " is " RD "not" C  " in " G "List" NC << std::endl;

			// Catch errors
		} catch (const std::exception & e) { std::cerr << RD " Error: " C << e.what() << NC << std::endl; }
	
	}
	std::cout << std::endl << " =======================================" << std::endl << std::endl;
}
