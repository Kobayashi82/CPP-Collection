/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:59:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/02/22 18:24:00 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

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

# include <iostream>
# include <string>

class Weapon {

private:
	
	std::string _Type;

public:

	Weapon(std::string Name);
	~Weapon();

	std::string const &getType() const;
	void setType(std::string Type);
	
};

#endif