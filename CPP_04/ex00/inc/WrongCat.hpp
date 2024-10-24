/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:41:49 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 19:16:30 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

	public:

		WrongCat();
		WrongCat(const WrongCat & src);
		~WrongCat();

		WrongCat & operator=(const WrongCat & WrongCat);

		void makeSound() const;

};
