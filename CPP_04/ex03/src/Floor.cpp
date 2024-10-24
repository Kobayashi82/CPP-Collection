/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 21:18:09 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/09 00:26:06 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"

//	Initializing the private variables
AMateria **	Floor::_floor = NULL;
int			Floor::_size = 0;

//	Add a material to the _floor array
//	To resize it, I create a temporary array with the new size, copy _floor to the temporary array
//	add the new material and update the _floor pointer to the new array
void Floor::add(AMateria * m) {
	if (!m) return ;
	AMateria ** tmp = new AMateria * [_size + 1];
	for (int i = 0; i < _size; i++) tmp[i] = _floor[i];
	tmp[_size] = m;
	delete[] _floor;
	_floor = tmp;
	_size++;
}

//	Frees all the materials in the _floor array
void Floor::clear() {
	if (!_size) return ;
	for (int i = 0; i < _size; i++) delete _floor[i];
	delete[] _floor;
	_floor = NULL;
	_size = 0;
}
