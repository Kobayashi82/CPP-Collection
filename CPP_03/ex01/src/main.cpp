/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 18:31:04 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int main() {
	std::string	Name = "Wall-E";
	std::cout << std::endl;
	std::cout << " ——————————————————————————————————————" << std::endl << std::endl;
	std::cout << C " A " G "derived class" C " is a type of class that " G "inherits" C " its attributes and methods from another" << std::endl
			  << " class, which would become its " G "base class" C "." << std::endl << std::endl
			  << " A class can have different properties for its members that indicate theirs " G "visibility" C ":" << std::endl << std::endl
			  << Y " Public:" C "\tIts members are accessible from anywhere if the object is accessible" << std::endl
			  << Y " Private:" C "\tIts members are only accessible from within the same class." << std::endl
			  << Y " Protected:" C "\tIt is similar to " Y "Private" C " but its members can also be accessed from " G "derived classes" C << std::endl << std::endl
			  << " When a " G "derived class" C " is created from another, the constructor of the " G "base class" C " is called" << std::endl
			  << " before the " G "derived class" C " is created." << std::endl << std::endl
			  << " Similarly, they must be destroyed in the reverse order of creation, because otherwise, we might" << std::endl
			  << " encounter situations where the" G " derived class" C " would try to access members of the " G "base class" C " when" << std::endl
			  << " they have been destroyed." << std::endl << std::endl
			  << " Fortunately, the destruction of the " G "base class" C " is managed by the system, and it does not depend on" << std::endl
			  << " us having to destroy one class before another." << std::endl << std::endl

			  << " In this exercise, we create a " G "derived class " Y "ScavTrap" C " from " Y "ClapTrap" C ". This new class " G "inherits" C " the" << std::endl
			  << " members of " Y "ClapTrap" C ", therefore we can call the members of " Y "ClapTrap" C " from " Y "ScavTrap" C "." << std::endl << std::endl
			  << " Likewise, we can add new methods to the " Y "ScavTrap" C " class, further expanding the destructive" << std::endl
			  << " possibilities of " Y << Name << C "." NC << std::endl << std::endl
			  << " ——————————————————————————————————————" << std::endl << std::endl;
	{
		ScavTrap Robot(Name); std::cout << std::endl;
		std::cout << Y << Name << C " has been constructed" << std::endl
				  << Y "[" G "Hit Points" Y "]" C " = " NC "100" C "       " Y "[" G "Energy Points" Y "]" C " = " NC "50" C "       " Y "[" G "Attack Points" Y "]" C " = " NC "20" << std::endl << std::endl;
		std::cout << std::endl << " ——————————————————————————————————————" << std::endl << std::endl;

		std::cout << Y << Name << C " has attacked a " Y "human" C " by jumping on him" << std::endl << std::endl;
		Robot.attack("Human"); 			std::cout << std::endl;
		std::cout << std::endl << NC " ——————————————————————————————————————" << std::endl << std::endl;

		std::cout << Y << Name << C " has injured the human, but has taken damage" << std::endl << std::endl;
		Robot.takeDamage(35); 			std::cout << std::endl;
		std::cout << std::endl << NC " ——————————————————————————————————————" << std::endl << std::endl;

		std::cout << Y << Name << C " is in repair mode" NC << std::endl << std::endl;
		Robot.beRepaired(15); 			std::cout << std::endl;
		std::cout << std::endl << NC " ——————————————————————————————————————" << std::endl << std::endl;

		Robot.guardGate();				std::cout << std::endl;
		std::cout << std::endl << NC " ——————————————————————————————————————" << std::endl << std::endl;
		std::cout << std::endl << Y << Name << C " has exhausted its energy source and has shut down" << std::endl
				  << Y "[" G "Hit Points" Y "]" C " = " NC "0" C "       " Y "[" G "Energy Points" Y "]" C " = " NC "0" << std::endl << std::endl;
	}
	std::cout << std::endl;
	std::cout << " ——————————————————————————————————————" << std::endl << std::endl;
}
