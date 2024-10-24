/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:25:05 by vzurera-          #+#    #+#             */
/*   Updated: 2024/06/25 09:17:52 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
	std::cout << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	std::cout << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	std::cout << "\n	In the first case, we have created a class " Y UN "HumanA" NC " that requires\n"
     	         "	a name and a weapon at the time of creation, in its constructor.\n"
                 "	The weapon is created and passed by reference. That is, a copy will not be made.\n\n"
                 "	The " Y UN "HumanA" NC " class stores the weapon as a " C "reference" NC " to the original object.\n\n"
                 "	In the case of " Y "Jim" NC ", we have created him with the class " Y UN "HumanB" NC ". This class does not require\n"
                 "	a weapon at creation, but one can be assigned with " C UN "setWeapon()" NC " by passing it by reference.\n\n"
                 "	The " Y UN "HumanB" NC " class stores the weapon as a " C "pointer" NC " to the original object.\n";
	std::cout << std::endl;
}