/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:13:18 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/08 00:07:53 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//	CONSTRUCTORS

Span::Span(const size_t & N) : _size(N) {}

//	Constructor that generates random numbers
Span::Span(const size_t & N, bool Random) : _size(N), _array(0) {
	if (Random) {
		_array.resize(N);
		if (_array.size() > _size) throw std::out_of_range("Max size reached"); 
	 	std::generate(_array.begin(), _array.end(), std::rand);
	}
}

Span::Span(const Span & src) { *this = src; }
Span::~Span() {}

//	FUNCTIONS

const std::vector<int> * Span::getArray() const { return (&_array); }

//	Add a single item
void Span::addNumber(const int & N) { if (_array.size() > _size) throw std::out_of_range("Max size reached"); else _array.push_back(N); }

//	Add a range from another container
void Span::addNumber(std::vector <int> ::const_iterator begin, std::vector <int> ::const_iterator end) {
	if (_array.size() + std::distance(begin, end) > _size) throw std::out_of_range("The range will exceed the maximum size"); 
	_array.insert(_array.end(), begin, end);
}

//	First, we need at least two elements to be able to obtain the span
//	Then we copy, sort the container, and iterate through it comparing values in pairs to obtain the smallest span
size_t Span::shortestSpan() const {
	if (_array.size() < 2) throw std::invalid_argument("Not enough elements to find a span");
	std::vector <int> sortedArray = _array;
    std::sort(sortedArray.begin(), sortedArray.end());
    size_t shortest = std::numeric_limits<size_t>::max();
    for (size_t i = 0; i < sortedArray.size() - 1; ++i) {
        size_t span = sortedArray[i + 1] - sortedArray[i];
        if (span < shortest) shortest = span;
    } return (shortest);
}

//	We simply subtract the smaller number from the larger number
size_t Span::longestSpan() const {
    if (_array.size() < 2) throw std::invalid_argument("Not enough elements to find a span");
    return (*std::max_element(_array.begin(), _array.end()) - *std::min_element(_array.begin(), _array.end()));
}

//	OVERLOADS

Span & Span::operator=(const Span & rhs) { if (this != &rhs) { _size = rhs._size; _array = rhs._array; } return (*this); }

//	I have decided to sort the list before inserting it
std::ostream & operator<<(std::ostream & os, const Span & rhs) {
	std::vector <int> sortedArray = *(rhs.getArray());
    std::sort(sortedArray.begin(), sortedArray.end());
    for (std::vector<int>::const_iterator it = sortedArray.begin(); it != sortedArray.end(); ++it) os << *it << " ";
    return (os);
}
