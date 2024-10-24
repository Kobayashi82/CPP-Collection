/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 20:26:27 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Serializer.hpp"
#include <iostream>

int main( void ) {
	std::cout << std::endl << " ======================================" << std::endl << std::endl
			<< BR " In this exercise, we use " B "reinterpret_cast" BR " which allows us to convert " B "pointers" BR " or " B "references" BR " of one" << std::endl
			<< " type to another type." << std::endl << std::endl
			<< " When " G "serializing" BR " the information of the " B "Data" BR ", what we do is convert a " B "pointer" BR " to a " B "numeric" BR " value" BR << std::endl
			<< " and when " G "deserializing" BR " we do the opposite, convert the " B "numeric" BR " value back to a " B "pointer" BR "." << std::endl << std::endl
			<< " One of the uses of " G "serialization" BR " is to be able to save " B "objects" BR " or any data in a file or send it" << std::endl
			<< " through a connection to then " G "deserialize" BR " it and restore its state." << std::endl << std::endl
			<< " It works for any type of data, whether they are "B "structures" BR ", " B "classes" BR ", " B "variables" BR ", etc..." NC << std::endl << std::endl;
	{
		std::cout <<   " ======================================" << std::endl
				  << G "             SERIALIZE TESTS           " NC << std::endl
				  <<   " ======================================" << std::endl << std::endl;

		Data data1;
		Data data2;
		Data *data = &data1;

        data1.Something = 42;
		data2.Something = 1234;
		
		std::cout << G " Data" C " has changed his pointer to " G "Data 1" C " and his address is:\t" Y << data << std::endl
				  << C " Variable " Y "Something" C " of " B "Data" C " is \t\t\t\t\t" G << data->Something << NC << std::endl << std::endl;

        uintptr_t Serialized = Serializer::serialize(data);
		std::cout << G " Data" C " Serialized:\t" Y << Serialized << NC << std::endl << std::endl;

		data = &data2;
		std::cout << G " Data" C " has changed his pointer to " G "Data 2" C " and his address is:\t" RD << data << std::endl
				  << C " Variable " Y "Something" C " of " B "Data" C " is \t\t\t\t\t" G << data->Something << NC << std::endl << std::endl;

		data = Serializer::deserialize(Serialized);
		std::cout << G " Data" C " Des-Serialized:\t" Y << Serialized << NC << std::endl
				  << G " Data" C " has changed his pointer to the value Des-Serialized" << std::endl << std::endl
				  << G " Data" C " has his pointer now in the address:\t\t\t" Y << data << std::endl
				  << C " Variable " Y "Something" C " of " B "Data" C " is \t\t\t\t\t" G << data->Something << NC << std::endl << std::endl;
	}
	std::cout << " =======================================" << std::endl << std::endl;
}
