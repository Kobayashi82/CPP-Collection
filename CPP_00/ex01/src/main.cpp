/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:52:18 by vzurera-          #+#    #+#             */
/*   Updated: 2024/05/11 17:31:23 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int	main() {
	PhoneBook	PhoneBook;

	std::string command;

	std::cout << std::endl << Y "	" UN "PHONE BOOK 1.0" NC << std::endl;
    while (true) {
		std::cout << std::endl << C "Please, enter a command:	" NC;
		if (!std::getline(std::cin, command)) {
			std::cout << std::endl << std::endl;
			break;
		}
		if (command.empty()) {
			std::cout << "\033[1A\033[1A";
			continue;
        }
        if (command == "ADD" || command == "add" || command == "Add") {
			PhoneBook.Add();
        } else if (command == "SEARCH" || command == "search" || command == "Search") {
            PhoneBook.Search();
        } else if (command == "EXIT" || command == "exit" || command == "Exit") {
            std::cout << std::endl;	break;
        } else {
            std::cout << std::endl << RD "	Accepted commands: " << std::endl << std::endl
					  << Y "    ADD:		" << C "Add a new contact" << std::endl
					  << Y "    SEARCH		" << C "Search for a contact" << std::endl
					  << Y "    EXIT		" << C "Close the program" NC << std::endl;
        }
    }
}
