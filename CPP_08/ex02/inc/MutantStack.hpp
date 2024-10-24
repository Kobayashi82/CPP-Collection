/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 00:30:17 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/08 00:59:03 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <deque>

//	Template declaration for MutantStack, a class that inherits from std::stack.
//	It allows for iteration over the stack elements by exposing the underlying container's iterators (deque in this case).
//	T is the type of the elements stored in the stack.
//	Container is the type of the underlying container, defaulting to std::deque (double-ended queue).
template <typename T, class Container = std::deque <T> > class MutantStack : public std::stack <T, Container> {

	public:

		typedef typename Container::iterator iterator;

		MutantStack() {}
		MutantStack(const MutantStack & rhs) { *this = rhs; }
		~MutantStack() {}
		MutantStack & operator=(const MutantStack & rhs) { std::stack <T, Container>::operator=(rhs); return (*this); }

		iterator begin() { return (this->c.begin()); }
		iterator end() { return (this->c.end()); }

};
