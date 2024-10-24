/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 20:44:49 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Array.hpp"
#include <iostream>

int main() {
	std::cout << std::endl << " ======================================" << std::endl << std::endl
			  << BR " In this last exercise, we created a " Y "template" BR " to handle " G "arrays" BR " of different data " Y "types" BR "." << std::endl << std::endl
              << " We must ensure that the " C "creation" BR ", " C "copy" BR ", and " C "access" BR " operations are " G "safe" BR"." << std::endl << std::endl
              << " And of course, release the " B "objects" BR " we " G "create" BR "." << std::endl << std::endl
              << G " Thank you for evaluating me." NC << std::endl << std::endl;
	{
		//	SOME TEST

		std::cout <<   " ======================================"    << std::endl
				  << G "              ARRAY TESTS              " NC << std::endl
				  <<   " ======================================"    << std::endl << std::endl;
		
		try {

			//	CREATE EMPTY ARRAY
			try {
				Array<int> emptyArray;
				std::cout << BR " Creating an empty " G "array" BR " \t\t\t" Y "The array is " B << emptyArray << NC << std::endl << std::endl;
			} catch (const std::exception & e) { std::cout << RD "Error: " Y  << e.what() << NC << std::endl << std::endl; }

			//	CREATE ARRAY WITH SIZE 0
			try { std::cout << BR " Creating an " G "array" BR " with size (" B "0" BR ")\t\t" NC;
			Array<int> zeroSizeArray(0); std::cout << std::endl << std::endl; }
			catch (const std::exception & e) { std::cout << RD "Error: " Y  << e.what() << NC << std::endl << std::endl; }

			std::cout << std::endl << NC " ——————————————————————————————————————" << std::endl << std::endl;

			//	CREATE INTEGER ARRAY OF SIZE 5
			try { std::cout << BR " Creating an " G "array" BR " of " C "integers" BR " (" B "5" BR ")\t\t" NC;
			Array<int> intArray(5); std::cout << Y "Array created " B "succesfully" NC << std::endl; }
			catch (const std::exception & e) { std::cout << RD "Error: " Y  << e.what() << NC << std::endl; }

			//	DISPLAY CONTENT OF INTEGER ARRAY
			Array<int> intArray(5); for (size_t i = 0; i < intArray.size(); i++) intArray[i] = i * 10;
			try { std::cout << BR " The " G "array" BR " content is (" B "index" BR " * " B "10" BR ")\t\t" Y << intArray << NC << std::endl << std::endl; }
			catch (const std::exception & e) { std::cout << RD "Error: " Y  << e.what() << NC << std::endl << std::endl; }

			//	OUT OF RANGE INDEX FOR INTEGER ARRAY
			try { std::cout << BR " Accessing to an " B "index" BR " out of range (" B "999" BR ")\t" NC << intArray[999] << std::endl << std::endl; }
			catch (const std::exception & e) { std::cout << RD "Error: " Y  << e.what() << NC << std::endl << std::endl; }

			//	CREATE INTEGER ARRAY FROM ANOTHER INTEGER ARRAY (COPY CONSTRUCTOR)
			try {
				std::cout << BR " Creating new " G "array" BR " from the " C "integer" BR " " G "array" BR " \t" NC;
				Array<int> anotherIntArray = intArray; std::cout << Y "Array created " B "succesfully" NC << std::endl;
				std::cout << BR " The new " C "integer " G "array" BR " content is \t\t" Y << intArray << NC << std::endl << std::endl;
			} catch (const std::exception & e) { std::cout << RD "Error: " Y  << e.what() << NC << std::endl << std::endl; }

			std::cout << std::endl << NC " ——————————————————————————————————————" << std::endl << std::endl;

			//	CREATE STRING ARRAY OF SIZE 3
			try { std::cout << BR " Creating an " G "array" BR " of " C "strings" BR " (" B "3" BR ")\t\t" NC;
			Array<std::string> stringArray(3); std::cout << Y "Array created " B "succesfully" NC << std::endl; }
			catch (const std::exception & e) { std::cout << RD "Error: " Y  << e.what() << NC << std::endl; }

			//	DISPLAY CONTENT OF STRING ARRAY
			Array<std::string> stringArray(3); stringArray[0] = "Hello"; stringArray[1] = "World"; stringArray[2] = "!";
			try { std::cout << BR " The " G "array" BR " content is (" B "Hello" BR ", " B "World" BR ", " B "!" BR ")\t\t" Y << stringArray << NC << std::endl << std::endl; }
			catch (const std::exception & e) { std::cout << RD "Error: " Y  << e.what() << NC << std::endl << std::endl; }

			//	COPY STRING ARRAY TO ANOTHER STRING ARRAY (COPY OPERATOR)
			try {
				std::cout << BR " Copying the " C "string " G "array" BR " to new " G "array" BR " \t\t" NC;
				Array<std::string> anotherStringArray = stringArray; std::cout << Y "Array copied " B "succesfully" NC << std::endl;
				std::cout << BR " The new " C "string " G "array" BR " content is \t\t" Y << stringArray << NC << std::endl << std::endl;
			} catch (const std::exception & e) { std::cout << RD "Error: " Y  << e.what() << NC << std::endl << std::endl; }

		} catch (const std::exception & e) {
			std::cout  << std::endl << RD "Error: " Y  << e.what() << NC << std::endl;
		}
	}
	std::cout << " =======================================" << std::endl << std::endl;
}
