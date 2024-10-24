/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:45:39 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 19:20:59 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Colors.hpp"
#include <iostream>

class Brain {

	public:

		//	Constructors

		Brain();
		Brain(const Brain & src);
		virtual ~Brain();

		//	Variables

		std::string ideas[100];

		//	Overloads

		Brain & operator=(const Brain & Brain);
};
