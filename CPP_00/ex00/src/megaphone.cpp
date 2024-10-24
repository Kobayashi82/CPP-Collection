/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:52:18 by vzurera-          #+#    #+#             */
/*   Updated: 2024/05/11 17:02:03 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	} else {
		argv++;
		while (--argc)
		{
			std::string arg = *argv;
			int i = arg.find_first_not_of(' ');
			int j = arg.find_last_not_of(' ');
			while ((*argv)[i] && i <= j && i != -1 && j != -1)
				std::cout << (char) std::toupper((*argv)[i++]);
			if (argc > 1 && i != -1 && j != -1) std::cout << ' ';
			argv++;
		}
		std::cout << std::endl;
	}
}
