/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 18:16:25 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int main() {
	std::string	Name = "Bender";
	std::cout << std::endl;
	std::cout << " ——————————————————————————————————————" << std::endl << std::endl;
	std::cout << C " This exercise is the same as the previous one, the only difference is that the class is called" << std::endl
			  << Y " FragTrap" C ", its characteristics have changed a bit (" G "Hit Points" C ", "G "etc" C ".) and it has a different method." << std::endl << std::endl
			  << " In summary, " Y "ScavTrap" C " and " Y "FragTrap" C " are " G "derived classes" C " from " Y "ClapTrap" C "." NC << std::endl << std::endl
			  << " ——————————————————————————————————————" << std::endl << std::endl;
	{
		FragTrap Robot(Name); std::cout << std::endl;
		std::cout << Y << Name << C " has been constructed" << std::endl
				  << Y "[" G "Hit Points" Y "]" C " = " NC "100" C "       " Y "[" G "Energy Points" Y "]" C " = " NC "100" C "       " Y "[" G "Attack Points" Y "]" C " = " NC "30" << std::endl << std::endl;
		std::cout << std::endl << " ——————————————————————————————————————" << std::endl << std::endl;

		std::cout << Y << Name << C " has seen the human who damaged " Y "Wall-E" C " and wants revenge" << std::endl << std::endl;
		Robot.attack("Human"); 			std::cout << std::endl;
		std::cout << std::endl << " ——————————————————————————————————————" << std::endl << std::endl;

		std::cout << C "The human has taken some damage, but has smashed " Y << Name << "'s" C " face" << std::endl << std::endl;
		Robot.takeDamage(99); 			std::cout << std::endl;
		std::cout << std::endl << " ——————————————————————————————————————" << std::endl << std::endl;

		std::cout << Y << Name << C " is in repair mode" NC << std::endl << std::endl;
		Robot.beRepaired(99); 			std::cout << std::endl;
		std::cout << std::endl << " ——————————————————————————————————————" << std::endl << std::endl;

		std::cout << Y << Name << C " is very happy to have fully recovered" << std::endl << std::endl;
		Robot.highFivesGuys(); 			std::cout << std::endl;
		std::cout << C "But there is no one to return the high five" NC << std::endl << std::endl;
		std::cout << std::endl << " ——————————————————————————————————————" << std::endl << std::endl;
		
		std::cout << Y << Name << C " is now so sad that it has self-destructed" << std::endl
				  << Y "[" G "Hit Points" Y "]" C " = " NC "0" C "       " Y "[" G "Energy Points" Y "]" C " = " NC "0" << std::endl << std::endl;
	}
	std::cout << std::endl;
	std::cout << " ——————————————————————————————————————" << std::endl << std::endl;

}
