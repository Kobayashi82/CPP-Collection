/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:47:38 by vzurera-          #+#    #+#             */
/*   Updated: 2024/02/23 00:40:29 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv) {
	Harl Harl;

	if (argc != 2)
	{
		std::cout << std::endl << RD "	Usage:" G " ./harlFilter " G "[" B "DEBUG" W ", " C "INFO" W ", " Y "WARNING" W ", " RD "ERROR" G "]" NC << std::endl << std::endl;
		return (1);
	}
	std::string Level = argv[1];
	for (size_t i = 0; i < Level.length(); ++i) Level[i] = std::toupper(Level[i]);
	std::cout << std::endl;
	Harl.complain(Level);
	return (0);
}