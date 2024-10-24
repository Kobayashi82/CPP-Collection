/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:47:38 by vzurera-          #+#    #+#             */
/*   Updated: 2024/02/22 23:19:21 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

int	main(int argc, char **argv) {
	int	Replaces = 0;
	if (argc != 4 || argv[1][0] == '\0' || argv[2][0] == '\0') {
		std::cout << std::endl << RD "	Incorrect Arguments: " C "The program expects " Y "3" C " arguments" << std::endl << std::endl;
		std::cout << G "		./Replacer " Y "[File] [String_1] [String_2]" << std::endl << std::endl;
		std::cout << Y "	    File:	" C "File where you want to perform the string replacement operation" << std::endl;
		std::cout << Y "	String_1:	" C "String you want to replace within the file. Cannot be an empty string" << std::endl;
		std::cout << Y "	String_2: 	" C "String that will replace " Y "String_1" C " in the file" NC << std::endl << std::endl;
		return (1);
	}
	try {
		Replacer Replacer(argv[1]);
		if ((Replaces = Replacer.replace(argv[2], argv[3])) < 0)
		{
			std::cout << std::endl << RD "	Error while performing the replacement operation" NC << std::endl << std::endl;
			return (1);
		}
	}
	catch(const std::runtime_error& e) {
		std::cout << std::endl << RD "	" << std::string(e.what()) << NC "" << std::endl << std::endl;
		return (1);
	}
	if (Replaces == 0)
		std::cout << std::endl << C "	No matches found" NC << std::endl << std::endl;
	else if (Replaces == 1)
		std::cout << std::endl << C "	" Y << Replaces << C " replacement have been made" NC << std::endl << std::endl;
	else
		std::cout << std::endl << C "	" Y << Replaces << C " replacements have been made" NC << std::endl << std::endl;
	return (0);
}