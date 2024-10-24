/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:59:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/02/22 18:29:15 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {

private:
	
	std::string _Name;
	Weapon *_Weapon;

public:

	HumanB(std::string Name);
	~HumanB();

	void setWeapon(Weapon &New_Weapon);
	void attack();
};

#endif