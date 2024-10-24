/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:41:49 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 19:46:54 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongCat : public WrongAnimal {

	private:

		Brain* _Brain;

	public:

		//	Constructors

		WrongCat();
		WrongCat(const WrongCat & src);
		~WrongCat();

		//	Functions

		void makeSound() const;
		void setIdea(const int i, std::string idea);
		std::string getIdea(const int i) const;

		//	Overloads

		WrongCat & operator=(const WrongCat & WrongCat);

};
