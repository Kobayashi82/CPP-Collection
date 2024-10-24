/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:27:12 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 19:20:50 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Colors.hpp"
#include <iostream>

class Animal {

	protected:
	
		std::string _type;

	public:

		//	Constructors

		Animal();
		Animal(const std::string Type);
		Animal(const Animal & src);
		virtual ~Animal();

		//	Functions

		std::string getType() const;
		virtual void makeSound() const;

		//	Overloads

		Animal & operator=(const Animal & Animal);

};
