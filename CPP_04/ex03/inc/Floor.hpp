/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 21:14:25 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/09 00:25:49 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class AMateria; 
class Floor {

	private:							//	This is a class that has all its methods static and therefore
										//	can be used without needing to instantiate the class
		static AMateria **	_floor;
		static int			_size;

	public:

		static void add(AMateria * m);
		static void clear();

};