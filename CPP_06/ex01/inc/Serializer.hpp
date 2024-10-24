/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:22:06 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/06 18:34:06 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include <stdint.h>

struct Data { int Something; };

class Serializer {

	private:

		Serializer();
		Serializer(const Serializer &);
		~Serializer();
		Serializer & operator=(const Serializer &);
		
	public:

		static uintptr_t serialize(Data * ptr);
		static Data* deserialize(uintptr_t raw);

};
