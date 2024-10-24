/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:51 by vzurera-          #+#    #+#             */
/*   Updated: 2024/02/21 16:47:07 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

Zombie* zombieHorde(int N, std::string name) {
    Zombie* Zombies = new Zombie[N];
    for(int i = 0; i < N; i++) {
        std::stringstream ss;
        ss << name << "_" << (i + 1);
        Zombies[i].setName(ss.str());
    }
    return (Zombies);
}