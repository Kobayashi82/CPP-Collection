/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:13:08 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/07 23:44:00 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <limits> 
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>

class Span {

	private:

		size_t				_size;
		std::vector <int>	_array;

		Span();
	
	public:

		Span(const size_t & N);
		Span(const size_t & N, bool Random);
		Span(const Span & src);
		~Span();
		Span & operator=(const Span & rhs);

		void addNumber(const int & N);
		void addNumber(std::vector <int> ::const_iterator begin, std::vector <int> ::const_iterator end);
		void addNumber();
		
		const std::vector<int> * getArray() const;

		size_t shortestSpan() const ;
		size_t longestSpan() const;

};

std::ostream & operator<<(std::ostream & os, const Span & rhs);
