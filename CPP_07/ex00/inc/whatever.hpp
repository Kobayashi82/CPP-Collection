/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 11:14:20 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/09 11:06:43 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template< typename T > void swap(T & a, T & b) { T tmp = a; a = b; b = tmp; }
template <typename T> T min(T & a, T & b) { if (a < b) return (a); else return (b); }
template <typename T> T max(T & a, T & b) { if (a > b) return (a); else return (b); }
