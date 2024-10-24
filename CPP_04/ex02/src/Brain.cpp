/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:45:48 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 19:18:30 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

//	Constructors

Brain::Brain() {
	std::cout << RD "Brain" C " constructor called" NC << std::endl;
}

Brain::Brain(const Brain & src) {
	std::cout << RD "Brain" C " copy constructor called" NC << std::endl;
	*this = src;
}

Brain::~Brain() {
	std::cout << RD "Brain" C " destructor called" NC << std::endl;
}

//	Overloads

//	A deep copy of the 'ideas' variable is performed
Brain & Brain::operator=(const Brain & rhs) {
	std::cout << RD "Brain" C " assignment operator called" NC << std::endl;
	for(int i = 0; i < 100; i++) ideas[i] = rhs.ideas[i];
	return (*this);
}
