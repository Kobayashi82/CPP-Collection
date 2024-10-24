/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/02/21 16:47:09 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main( void ) {
    int		nZombies = 10;
	Zombie	*Zombies = zombieHorde(nZombies, "Brian");

	std::cout << std::endl << G "   In this exercise, multiple objects are created in an array" << std::endl;
	std::cout << std::endl << C "   Press " Y UN "ENTER" NC C " to continue...";
	std::cin.get();
	std::cout << std::endl;
	for (int i = 0; i < nZombies; i++)
		Zombies[i].announce();
	std::cout << std::endl << G "   Now we can destroy all the objects" << std::endl;
	std::cout << std::endl << C "   Press " Y UN "ENTER" NC C " to continue...";
	std::cin.get();
	std::cout << std::endl;
	delete[] Zombies;
	std::cout << std::endl << G "   The objects are destroyed in the reverse order of their creation" << std::endl;
	std::cout << std::endl;
}
