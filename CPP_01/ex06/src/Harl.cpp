/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:14:22 by vzurera-          #+#    #+#             */
/*   Updated: 2024/02/23 00:41:15 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
}

Harl::~Harl() {
}

void Harl::complain(std::string Level) {
	void (Harl::*Functions[])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string Levels[] = { "DEBUG", "INFO", "WARNING", "ERROR"};
	int NumLevels = sizeof(Levels) / sizeof(Levels[0]);
	int i = 0;
	while (i < NumLevels && Levels[i].compare(Level)) i++;
	switch (i) {
		case 0: (this->*Functions[i++])(); // fall through
		case 1: (this->*Functions[i++])(); // fall through
		case 2: (this->*Functions[i++])(); // fall through
		case 3: (this->*Functions[i++])(); break;
		default:
			std::cout << C " Probably complaining about insignificant problems " NC << std::endl << std::endl;;
	}
	if (i < NumLevels) (this->*Functions[i])();
}

void Harl::debug() {
	std::cout << G "[ " B "DEBUG" G " ]:  " NC << std::endl
			  << W "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl
			  << "I really do!" << std::endl << std::endl;
}
void Harl::info() {
	std::cout << G "[ " C "INFO" G " ]:  " NC << std::endl
			  << W "Cannot believe adding extra bacon costs more money." << std::endl
			  << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}
void Harl::warning() {
	std::cout << G "[ " Y "WARNING" G " ]:  " NC << std::endl
			  << W "Think I deserve to have some extra bacon for free." << std::endl
			  << "I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}
void Harl::error() {
	std::cout << G "[ " RD "ERROR" G " ]:  " NC << std::endl
			  << W "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}