/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/08 00:25:22 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Span.hpp"
#include <iostream>
#include <fstream>

int main() {
	std::cout << std::endl << " ======================================" << std::endl << std::endl
			  << BR " In this exercise, we must create a " B "class" BR " that creates a " Y "container" BR " and stores " G "integers" BR "." << std::endl << std::endl
              << " We must have methods to " C "add" BR " a number to the " Y "container" BR " or a " C "range" BR " from another " Y "container" BR "." << std::endl << std::endl
              << " Additionally, we need to implement two methods that return the " C "smallest" BR " and " C "largest" G " span" BR " among the" << std::endl
              << " numbers in the " Y "container" BR "." << std::endl << std::endl
              << " In the following tests, I generate " B "50" BR " and " B "10000" BR " random numbers to obtain the " G "span" BR "." << std::endl << std::endl
              << " I have created a " B "constructor" BR " that initializes with random numbers, but to be able to demonstrate" << std::endl
              << " the functionality of adding with a " C "range" BR ", not all tests are initialized this way." << std::endl << std::endl
              << " To see the list of numbers, they are " G "saved" BR " in a file." << std::endl << std::endl
              << " It works with both " C "positive" BR " and " C "negative" BR " numbers, but the randomly generated numbers are " C "positive" BR "." NC << std::endl << std::endl;
	{
		try {

			std::cout <<   " ======================================" << std::endl
					<< G "             DEFAULT TESTS             " NC << std::endl 
					<<   " ======================================" << std::endl << std::endl;
			{
				Span sp = Span(5);

				sp.addNumber(6);
				sp.addNumber(3);
				sp.addNumber(9);
				sp.addNumber(17);
				sp.addNumber(11);

				std::cout << G "Array:\t\t " C << sp << std::endl << std::endl;

				std::cout << Y "Shortest Span:\t " B << sp.shortestSpan() << NC << std::endl;
				std::cout << Y "Longest  Span:\t " B << sp.longestSpan() << NC << std::endl << std::endl << std::endl;
			}

			std::cout << " ======================================" << std::endl
					<< G "            50 NUMBERS TESTS           " NC << std::endl 
					<<   " ======================================" << std::endl << std::endl;
		
			std::srand(time(0));
			{
				Span sp(50, true);

				std::cout << G "Array:\t\t " C << "Saved to " Y "50_Numbers.txt" C " ";
				std::ofstream outFile("50_Numbers.txt");
				if (outFile.is_open()) { outFile << sp << std::endl; outFile.close(); std::cout << G "succesfully" NC << std::endl << std::endl; } else { std::cout << RD "failed" NC << std::endl << std::endl; }
				
				std::cout << Y "Shortest Span:\t " B << sp.shortestSpan() << NC << std::endl;
				std::cout << Y "Longest  Span:\t " B << sp.longestSpan() << NC << std::endl << std::endl << std::endl;
			}

			std::cout <<   " ======================================" << std::endl
					<< G "          10.000 NUMBERS TESTS         " NC << std::endl 
					<<   " ======================================" << std::endl << std::endl;
	
			{
				std::vector <int> BigArray(10000);
				std::generate(BigArray.begin(), BigArray.end(), std::rand);

				Span sp(BigArray.size());
				sp.addNumber(BigArray.begin(), BigArray.end());

				std::cout << G "Array:\t\t " C << "Saved to " Y "10000_Numbers.txt" C " ";
				std::ofstream outFile("10000_Numbers.txt");
				if (outFile.is_open()) { outFile << sp << std::endl; outFile.close(); std::cout << G "succesfully" NC << std::endl << std::endl; } else { std::cout << RD "failed" NC << std::endl << std::endl; }

				std::cout << Y "Shortest Span:\t " B << sp.shortestSpan() << NC << std::endl;
				std::cout << Y "Longest  Span:\t " B << sp.longestSpan() << NC << std::endl << std::endl;
			}
			
		} catch (std::exception & e) { std::cout << RD " Error: " Y << e.what() << NC << std::endl << std::endl; }
	
	}
	std::cout << " =======================================" << std::endl << std::endl;
}
