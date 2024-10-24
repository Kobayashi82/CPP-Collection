/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:04:01 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/07 17:44:27 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Colors.hpp"
#include <iostream>
#include <algorithm>

//	To search within a container, we pass the range and the value to search for as arguments.
//	If the search reaches the end of the container, then there are no matches.
template <typename T> bool easyFind(T & container, int value) { return (std::find(container.begin(), container.end(), value) != container.end()); }

//	This template is used to print the array and highlight the number if it exists in the container
template <typename T> void printArray(const T * Array, size_t Size, const T & Number) {
    for (size_t i = 0; i < Size; ++i) {
        if (Array[i] == Number) std::cout << Y << Array[i]; else std::cout << B << Array[i];
        if (i < Size - 1) std::cout << BR ", "; else std::cout << NC;
    }
}
