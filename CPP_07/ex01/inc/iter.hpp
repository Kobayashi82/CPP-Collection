/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:07:48 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/09 11:09:58 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T> void iter(T * array, size_t length, void (*fun)(T &)) { for (size_t i = 0 ; i < length; i++) fun(array[i]); }
template <typename T> void print(T value) { std::cout << C " " << value << NC << std::endl; }