/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:27:12 by vzurera-          #+#    #+#             */
/*   Updated: 2024/02/24 16:36:28 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Colors.hpp"
#include <iostream>

class WrongAnimal {

	protected:
	
		std::string _type;

	public:

		// Constructors

		WrongAnimal();
		WrongAnimal(const std::string Type);
		WrongAnimal(const WrongAnimal & src);
		virtual ~WrongAnimal();

		//	Functions

		std::string getType() const;
		void makeSound() const;

		//	Overloads

		WrongAnimal & operator=(const WrongAnimal & WrongAnimal);

};
