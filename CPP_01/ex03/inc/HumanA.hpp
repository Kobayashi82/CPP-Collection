/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:59:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/02/22 18:31:20 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA {

private:
	
	std::string _Name;
	Weapon &_Weapon;

public:

	HumanA(std::string Name, Weapon &Weapon);
	~HumanA();

	void attack();
};

#endif