/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:41:49 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 19:24:53 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Dog : public Animal {

	public:

		//	Constructors

		Dog();
		Dog(const Dog & src);
		~Dog();

		//	Functions

		void makeSound() const;

		//	Overloads

		Dog & operator=(const Dog & Dog);

};
