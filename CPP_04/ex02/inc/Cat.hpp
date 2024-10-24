/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:41:49 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 19:19:49 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

	private:

		Brain* _Brain;

	public:

		//	Constructors

		Cat();
		Cat(const Cat & src);
		~Cat();

		//	Functions

		void makeSound() const;
		void setIdea(const int i, std::string idea);
		std::string getIdea(const int i) const;

		//	Overloads

		Cat & operator=(const Cat & Cat);

};
