/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:31:02 by vzurera-          #+#    #+#             */
/*   Updated: 2024/02/21 15:54:42 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	this->name = name;
}

Zombie::~Zombie() {
	std::cout << C "	The zombie \'" Y UN << name << NC C "\' has been defeated" NC << std::endl;
}

void Zombie::announce() const {
	std::cout << "	" <<  Y UN << name << ":" NC C " BraiiiiiiinnnzzzZ..." NC << std::endl;
}