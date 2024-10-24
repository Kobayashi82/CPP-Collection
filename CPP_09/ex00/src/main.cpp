/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/10 00:22:46 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout  << std::endl << RD "      Incorrect number of arguments" << std::endl << std::endl;
		std::cout << C "\tUsage: " Y "./btc [" G "Input File" Y "]" NC << std::endl << std::endl;
		return (0);
    }
	std::cout << std::endl << " ======================================" << std::endl << std::endl
			  << BR " This exercise involves creating a " C "program" BR " that calculates the " G "value" BR " of a certain" << std::endl
			  << " amount of " Y "Bitcoin" BR " on specific " G "dates" BR ". The program will use two " B "CSV" BR " files:" << std::endl << std::endl
			  << Y " Bitcoin Price Database:\t" BR "Contains the " Y "Bitcoin" BR " prices over time." << std::endl << std::endl
			  << Y " Input File:\t\t\t" BR "Specifies " G "dates" BR " and " G "values" BR " to evaluate." << std::endl << std::endl
			  << " The " Y "Input File" BR " must be passed as argument." << std::endl << std::endl
			  << " Each line in the " Y "Input File" BR " should follow the format " G "date" Y " | " G "value" BR "." << std::endl << std::endl
			  << G " Dates" BR " must be in the " C "Year" BR "-" C "Month" BR "-" C "Day" BR " format." << std::endl << std::endl
			  << G " Values" BR " must be either a " B "float" BR ", " B "double" BR " or an "B "integer" BR " between " B "0" BR " and " B "1000" BR "." << std::endl << std::endl
			  << " The program must handle and display appropriate " RD "error messages" BR " for invalid inputs." << std::endl << std::endl
			  << " If a specified " G "date" BR " does not exist in the " Y "Bitcoin Price Database" BR ", the program should" << std::endl
			  << " use the " C "closest" BR " preceding " G "date" BR "." << std::endl << std::endl
			  << " The program must use at least one " Y "container" BR " (" C "vector" BR ", " C "list" BR ", " C "map" BR ", " C "etc" BR "...) to store the data." << std::endl << std::endl
			  << " For each valid entry in the " Y "Input File" BR ", the program should output the " G "date" BR ", the " G "value" BR ", and the" << std::endl
			  << " calculated " G "result" BR " of the " G "value" BR " multiplied by the " Y "Bitcoin price" BR " on that " G "date" BR "." << std::endl << std::endl
			  << " For a " C "deeper" BR " explanation, review the " G "comments" BR " in the " G "code" BR "." NC << std::endl << std::endl;
	{
		std::cout << " ======================================" << std::endl << std::endl;

		bitcoinExchange(argv[1]);
	}
	std::cout  << std::endl << " =======================================" << std::endl << std::endl;
}
