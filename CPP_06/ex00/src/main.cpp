/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 20:34:21 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Converter.hpp"
#include <iostream>

int main(int argc, char ** argv) {

	if (argc != 2) {
		std::cout  << std::endl << RD "      Incorrect number of arguments" << std::endl << std::endl;
		std::cout << C "\tUsage: " Y "./Convert [" G "Number" Y "]" NC << std::endl << std::endl;
		return (0);
    }

	std::cout << std::endl << " ======================================" << std::endl << std::endl
			<< BR " These exercises are about " B "casting" BR " and its different types." << std::endl << std::endl
			<< " We are asked to use a different type of " B "casting" BR " in each exercise." << std::endl
			<< " Which one we use is up to us." << std::endl << std::endl
			<< " Of course, depending on the exercise, there are types of " B "casting" BR " that work better than others." << std::endl << std::endl
			<< " The 4 types of " B "casting" BR " in "G "C++" BR " are the following:" << std::endl << std::endl
			<< Y " static_cast:" C "\t\tFor conversions between related types." << std::endl
			<< Y " dynamic_cast:" C "\t\tFor safe downcasting in class hierarchies." << std::endl
			<< Y " const_cast:" C "\t\tTo add or remove const from a variable." << std::endl
			<< Y " reinterpret_cast:" C "\tconvert pointers or references of one type to another type." BR << std::endl << std::endl
			<< " In this exercise, a " G "number" BR " or " G "character" BR " is received as an argument and is converted to" << std::endl
			<< " the 4 possible types of data (" G "char" BR ", " G "int" BR ", " G "float" BR " and " G "double" BR ")." << std::endl << std::endl
			<< " We also learn to create a " Y "utility class" BR ", which is a " B "non-instantiable" BR " class that contains" << std::endl
			<< " its methods " B "statics" BR "." << std::endl << std::endl
			<< " This type of " B "class" BR " can never be " B "instantiated" BR " and therefore does not need " G "constructors" BR << std::endl
			<< " or a " G "destructor" BR "." << std::endl << std::endl
			<< " It is worth noting that the " B "static" BR " methods of a " Y "utility class" BR " cannot access members that" << std::endl
			<< " are not declared as " B "static" BR "." << std::endl << std::endl
			<< " Additionally, it is possible to have normal " B "instantiable" BR " classes that contain " B "static" BR " methods" << std::endl
			<< " and that can be called without " B "instantiating" BR " the class." NC << std::endl << std::endl;
	{
		//	SOME TEST

		std::cout <<   " ======================================"    << std::endl
				  << G "            CONVERSION TEST            " NC << std::endl
				  <<   " ======================================"    << std::endl << std::endl;

		try { Converter::convert(argv[1]); }
	    catch(const std::exception & e) { std::cerr << RD " Error: " C << e.what() << std::endl; }
	}
	std::cout << std::endl << NC " =======================================" << std::endl << std::endl;
	return (0);
}
