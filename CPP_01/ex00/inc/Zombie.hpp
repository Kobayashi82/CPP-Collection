/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:43 by vzurera-          #+#    #+#             */
/*   Updated: 2024/06/25 08:26:21 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

# define NC   	"\033[0m"		// Default
# define RD		"\033[1;31m"	// Bold Red
# define G     	"\033[1;32m"	// Bold Gree
# define Y     	"\033[1;33m"	// Bold Yellow
# define B     	"\033[1;34m"	// Bold Blue
# define M     	"\033[1;35m"	// Bold Magenta
# define C     	"\033[1;36m"	// Bold Cyan
# define W     	"\033[1;37m"	// Bold White

# define UN 	"\033[4m"		// Underline
# define IT 	"\033[3m"		// Italic

class Zombie {

public :

	Zombie(std::string name);
	~Zombie();

	void announce() const;
	
private:

	std::string	name;

	Zombie();

};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif