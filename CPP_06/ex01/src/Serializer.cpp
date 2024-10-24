/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:22:22 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/06 19:11:31 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


uintptr_t Serializer::serialize(Data * ptr) { return (reinterpret_cast<uintptr_t>(ptr)); }

Data * Serializer::deserialize(uintptr_t raw) { return (reinterpret_cast<Data *>(raw)); }
