/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:41:49 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 19:15:51 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Cat : public Animal {

	public:

		//	Constructors

		Cat();
		Cat(const Cat & src);
		~Cat();

		//	Functions

		void makeSound() const;

		//	Overloads

		Cat & operator=(const Cat & Cat);

};
