/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:41:49 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 19:33:32 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

	private:

		Brain * _Brain;

	public:

		//	Constructors

		Dog();
		Dog(const Dog & src);
		~Dog();

		//	Functions

		void makeSound() const;
		void setIdea(const int i, std::string idea);
		std::string getIdea(const int i) const;

		//	Overloads

		Dog & operator=(const Dog & Dog);

};
