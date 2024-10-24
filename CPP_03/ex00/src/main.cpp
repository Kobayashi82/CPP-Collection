/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 18:26:02 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main() {
	std::string	Name = "Mr. Robot";
	std::cout << std::endl;
	std::cout << " ——————————————————————————————————————" << std::endl << std::endl;
	std::cout << C " In this exercise, a simple class is created that simulates the behavior of a robot." << std::endl << std::endl
			  << " It's not very difficult, as we encounter the usual suspects (" Y "constructor" C "," Y << std::endl
			  << " copy constructor" C "," Y " destructor" C ", and " Y "assignment operator" C ")." << std::endl << std::endl
			  << " However, in the following exercises, we will see how class " B "inheritance" C " works." << std::endl << std::endl
			  << " By default, the " Y "robots" C " created have " G "Hit Points" C ", which is their " B "health" C ", " G "Energy Points" C ", which" << std::endl
			  << " are spent performing an action (" B "attack" C " or " B "repair" C ") and " G "Attack Points" C ", which is the " B "damage" C << std::endl
			  << " received by a poor " RD "victim" C "." NC << std::endl << std::endl

			  << " ——————————————————————————————————————" << std::endl << std::endl;
	{
		ClapTrap Robot(Name); 	std::cout << std::endl;
		std::cout << Y << Name << C " has been constructed" << std::endl
				  << Y "[" G "Hit Points" Y "]" C " = " NC "10" C "       " Y "[" G "Energy Points" Y "]" C " = " NC "10" C "       " Y "[" G "Attack Points" Y "]" C " = " NC "0" << std::endl << std::endl;
		std::cout << std::endl << " ——————————————————————————————————————" << std::endl << std::endl;
		
		std::cout << Y << Name << C " has encountered a human and did not like the way he was looked at" << std::endl << std::endl;
		Robot.attack("Human"); 			std::cout << std::endl;
		std::cout << std::endl << " ——————————————————————————————————————" << std::endl << std::endl;

		std::cout << Y << Name << C " is so useless that he has hurt himself" << std::endl << std::endl;
		Robot.takeDamage(4); 			std::cout << std::endl;
		std::cout << std::endl << " ——————————————————————————————————————" << std::endl << std::endl;

		std::cout << Y << Name << C " is in repair mode" NC << std::endl << std::endl;
		Robot.beRepaired(2); 			std::cout << std::endl;
		std::cout << std::endl << " ——————————————————————————————————————" << std::endl << std::endl;
		
		std::cout << Y << Name << C " has self-destructed after repairing itself" << std::endl
				  << Y "[" G "Hit Points" Y "]" C " = " NC "0" C "       " Y "[" G "Energy Points" Y "]" C " = " NC "0" << std::endl << std::endl;
	}
	std::cout << std::endl;
	std::cout << " ——————————————————————————————————————" << std::endl << std::endl;
}
