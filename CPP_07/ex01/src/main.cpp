/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 20:40:01 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "iter.hpp"
#include <iostream>

int main() {
	std::cout << std::endl << " ======================================" << std::endl << std::endl
			  << BR " This exercise is a continuation of the previous one." << std::endl << std::endl
			  << " We simply have to create a " Y "template" BR " that receives an " B "array" BR ", its " B "length" BR ", and a " B "pointer" BR " to" << std::endl
			  << " a " C "function" BR "." << std::endl << std::endl
			  << " Then it must execute the " C "function" BR " passed as an argument with each of the " B "array's indices" BR "." << std::endl << std::endl
			  << " To demonstrate the functionality of the " Y "template" BR ", I have created another " Y "template" BR " that receives" << std::endl
			  << " any " Y "type" BR " of data and displays it on the screen." << std::endl << std::endl
			  << " It is " G "important" BR " to note that for it to work with " B "objects" BR " we create, the insertion operator " Y "<<" BR << std::endl
			  << " must be implemented." NC << std::endl << std::endl;
	{

		std::cout <<   " ======================================"    << std::endl
				  << G "            CONVERSION TEST            " NC << std::endl
				  <<   " ======================================"    << std::endl << std::endl;
		
		int intArray[] = {1, 2, 3, 4, 5};
		std::cout << BR " Array of integers: " B "{" Y "1" B ", " Y "2" B ", " Y "3" B ", " Y "4" B ", " Y "5" B "}" NC << std::endl << std::endl;
		iter(intArray, 5, print);
		std::cout << std::endl << std::endl << NC " ——————————————————————————————————————" << std::endl << std::endl;

		float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
		std::cout << BR " Array of floats: " B "{" Y "1.1f" B ", " Y "2.2f" B ", " Y "3.3f" B ", " Y "4.4f" B ", " Y "5.5f" B "}" NC << std::endl << std::endl;
		iter(floatArray, 5, print);
		std::cout << std::endl << std::endl << NC " ——————————————————————————————————————" << std::endl << std::endl;

		char charArray[] = {'h', 'e', 'l', 'l', 'o'};
		std::cout << BR " Array of characters: " B "{" Y "h" B ", " Y "e" B ", " Y "l" B ", " Y "l" B ", " Y "o" B "}" NC << std::endl << std::endl;
		iter(charArray, 5, print);
		std::cout << std::endl << std::endl << NC " ——————————————————————————————————————" << std::endl << std::endl;
		
		std::string strArray[] = {"hello,", "this", "is", "a", "test"};
		std::cout << BR " Array of strings: " B "{" Y "hello," B ", " Y "this" B ", " Y "is" B ", " Y "a" B ", " Y "test" B "}" NC << std::endl << std::endl;
		iter(strArray, 5, print); std::cout << std::endl;

	}
	std::cout << " =======================================" << std::endl << std::endl;
}
