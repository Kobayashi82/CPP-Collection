/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:53:19 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/07 13:54:27 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stdexcept>

template <typename T> class Array {

	private:

		T *		_array;
		size_t	_size;

	public:

		// Constructors

		Array() : _array(NULL), _size(0) {}
		Array(size_t Size) : _array(NULL), _size(Size) { if (_size == 0) throw std::out_of_range("Index out of range"); else { _array = new T[Size]; _size = Size; }}
		Array(const Array & src) : _array(NULL), _size(0) { *this = src; }
		~Array() { delete[] _array; }

		// Functions

		size_t size() const { return _size; }

		// Overloads

		Array & operator=(const Array & rhs) {
			if (this != &rhs) {
				if (rhs._size == 0) throw std::out_of_range("Index out of range");
				delete[] _array; _array = new T[rhs._size]; _size = rhs._size;
				for (size_t i = 0; i < _size; i++) _array[i] = rhs._array[i];
			} return *this;
		}

		T & operator[](size_t i) const { if (i >= _size) throw std::out_of_range("Index out of range"); else return _array[i]; }

};

template <typename T> std::ostream & operator<<(std::ostream & os, const Array<T> & rhs) {
	if (rhs.size() == 0)
		os << "NULL";
	else
		for (size_t i = 0; i < rhs.size(); i++) os << rhs[i] << " ";
	return os;
}
