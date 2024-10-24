/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:30:18 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/06 23:22:44 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Colors.hpp"
#include <iostream>
#include <sstream>
#include <limits>

class Converter {

	private:

		//	This is not needed, but just in case... (OCF ☹)
		Converter();
		Converter(const Converter &);
		~Converter();
		Converter & operator=(const Converter &);
		
	public:

		static void convert(std::string literal);

};
