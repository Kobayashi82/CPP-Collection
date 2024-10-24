/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 18:16:32 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main() {
	std::string	Name = "Optimus Prime";
	std::cout << std::endl;
	std::cout << " ——————————————————————————————————————" << std::endl << std::endl;
	std::cout << C " In this exercise, a class will be created that " G "inherits" C " from two classes that have the" << std::endl
			  << " same " G "base class" C "." << std::endl << std::endl
			  << " This is known as the " Y "diamond problem" C ", and to prevent a conflict from having a" << std::endl
			  << " duplicated " G "base class" C " the " Y "virtual" C " keyword is used." << std::endl << std::endl
			  << M " Virtual inheritance" C " is used to avoid the problem of " M "multiple inheritance" C ", which could" << std::endl
			  << " lead to ambiguities or duplication of " M "inherited members" C "." << std::endl << std::endl
			  << " In this case, the " Y "DiamondTrap" C " is a " G "derived class" C " of " Y "ScavTrap" C " and " Y "FragTrap" C ", but these two" << std::endl
			  << " classes must " G "inherit" C " from the " G "base class " Y "ClapTrap" C " using the " Y "virtual" C " keyword." << std::endl << std::endl
			  << " In this way, " Y "DiamondTrap" C " will have all the members of " Y "ClapTrap" C ", " Y "ScavTrap" C ", and " Y "FragTrap" C "." << std::endl << std::endl
			  << " Of course, the order of creation is maintained, going from the " G "base class" C " to the last " << std::endl
			  << G " derived class" C " and vice versa when they are destroyed." << std::endl << std::endl
			  << " Being " Y "DiamondTrap" C " a " G "derived class" C " of " Y "ScavTrap" C " and " Y "FragTrap" C ", features of one and the other" << std::endl
			  << " can be used creating a robot with the " G "Attack Points" C " of " Y "FragTrap" C " and the " G "Energy Points" C " of " Y "ScavTrap" C "." NC << std::endl << std::endl
			  << " ——————————————————————————————————————" << std::endl << std::endl;
	{
		DiamondTrap Robot(Name);		std::cout << std::endl;
		std::cout << Y << Name << C " has been constructed" << std::endl
				  << Y "[" G "Hit Points" Y "]" C " = " NC "100" C "       " Y "[" G "Energy Points" Y "]" C " = " NC "50" C "       " Y "[" G "Attack Points" Y "]" C " = " NC "30" << std::endl << std::endl;
		std::cout << std::endl << " ——————————————————————————————————————" << std::endl << std::endl;

		std::cout << Y << Name << C " accidentally ran over a " Y "human" NC << std::endl << std::endl;
		Robot.attack("Human"); 			std::cout << std::endl;
		std::cout << std::endl << " ——————————————————————————————————————" << std::endl << std::endl;

		std::cout << Y << Name << C " has received damage to its bumper" NC << std::endl << std::endl;
		Robot.takeDamage(13); 			std::cout << std::endl;
		std::cout << std::endl << " ——————————————————————————————————————" << std::endl << std::endl;

		std::cout << Y << Name << C " is in repair mode" NC << std::endl << std::endl;
		Robot.beRepaired(7); 			std::cout << std::endl;
		std::cout << std::endl << " ——————————————————————————————————————" << std::endl << std::endl;

		std::cout << Y << Name << C " is monitoring its garage" NC << std::endl << std::endl;
		Robot.guardGate(); 				std::cout << std::endl;
		std::cout << std::endl << " ——————————————————————————————————————" << std::endl << std::endl;
		
		std::cout << Y << Name << C " has finished its surveillance and is going to drink fuel with its friends" NC << std::endl << std::endl;
		Robot.highFivesGuys(); 			std::cout << std::endl;
		std::cout << C "All his friends have given him a high five" << NC << std::endl << std::endl;
		std::cout << std::endl << " ——————————————————————————————————————" << std::endl << std::endl;

		std::cout << Y << Name << C << " is so drunk that he needs to be reminded of his name" << NC << std::endl << std::endl;
		Robot.whoAmI(); 				std::cout << std::endl;
		std::cout << std::endl << " ——————————————————————————————————————" << std::endl << std::endl;

		std::cout << C "After the party, it's time for " Y << Name << C " to turn off the engine and rest" NC << std::endl
				  << Y "[" G "Hit Points" Y "]" C " = " NC "0" C "       " Y "[" G "Energy Points" Y "]" C " = " NC "0" << std::endl << std::endl;
	}
	std::cout << std::endl;
	std::cout << " ——————————————————————————————————————" << std::endl << std::endl;
}
