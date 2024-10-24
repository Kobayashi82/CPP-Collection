/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/06/24 19:17:56 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main( void ) {
    std::string name;

	std::cout << std::endl << G
	"	This exercise serves to understand the difference between" << std::endl
	<< "	    the STACK and the HEAP by working with classes" << std::endl << std::endl
    << "	" Y UN "STACK:	" NC C " Local variables and function context. Created and destroyed automatically" << std::endl
	<< "	 " Y UN "HEAP:	" NC C " Dynamic memory. Manual allocation and deallocation" << std::endl << std::endl;
	
	std::cout << G "		Creating zombie on the stack" NC << std::endl << std::endl;
    std::cout << RD "	Zombie Name: " C << std::flush;
    std::cin >> name;
	std::cout << std::endl;
    randomChump(name);
	std::cout << std::endl;
	
	std::cout << G "		Creating zombie on the heap" NC << std::endl << std::endl;
    std::cout << RD "	Zombie Name: " C << std::flush;
    std::cin >> name;
    Zombie *Zombie1 = newZombie(name);
	std::cout << std::endl;
	Zombie1->announce();
	std::cout << std::endl;
	delete Zombie1;
    std::cout << std::endl;
}
