/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 20:38:53 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "whatever.hpp"
#include <iostream>

int main() {
	std::cout << std::endl << " ======================================" << std::endl << std::endl
			  << BR " This exercise is about " Y "templates" BR "." << std::endl << std::endl
			  << Y " Templates" BR " are a feature that allows you to write generic and reusable code." << std::endl << std::endl
			  << " They can work with any " G "type" BR " of data or " B "objects" BR "." << std::endl << std::endl
			  << Y " Templates" BR " use placeholders for data " G "types" BR ". When you use the " C "function" BR " (because a " Y "template" BR << std::endl
			  << " is a " C "function" BR "), these placeholders are replaced with actual data " G "types" BR "." << std::endl << std::endl
			  << " This way, you can write one piece of code that works with different " Y "types" BR "." << std::endl << std::endl
			  << " Using " Y "templates" BR " provides us with many benefits, such as:" << std::endl << std::endl
			  << Y "   Reusability:\t\t" BR " Write code once and use it with any data " Y "type" BR "." << std::endl
			  << Y "   Flexibility:\t\t" C " Functions" BR " and " B "classes" BR " can handle different " G "types" BR " without rewriting." << std::endl
			  << Y "   Maintainability:\t" BR " Less code to manage and fewer chances for " RD "errors" BR "." << std::endl << std::endl
			  << " In these tests, " G "templates" BR " are used for the " C "functions" Y " swap()" BR ", " Y "min()" BR ", and " Y "max()" BR "," << std::endl
			  << " and these " C "functions" BR " are executed on " G "integer" BR " and " G "string" BR " data " Y "types" BR "." NC << std::endl << std::endl;
	{
		std::cout <<   " ======================================"    << std::endl
				  << G "              DEFAULT TEST             " NC << std::endl
				  <<   " ======================================"    << std::endl << std::endl;

		int a = 2;
		int b = 3;

		std::cout << Y " a" C " = " G << a << C ", " Y "b" C " = " G << b << NC << std::endl << std::endl;
		swap(a, b); std::cout << B " swap" C "(" Y "a" C ", " Y "b" C ")" << std::endl << std::endl;
		std::cout << Y " a" C " = " G << a << C ", " Y "b" C " = " G << b << NC << std::endl << std::endl;
		std::cout << B " min" C "(" Y "a" C ", " Y "b" C ") = " G << min(a, b) << NC << std::endl;
		std::cout << B " max" C "(" Y "a" C ", " Y "b" C ") = " G << max(a, b) << NC << std::endl << std::endl;

		std::cout << std::endl << NC " ——————————————————————————————————————" << std::endl << std::endl;

		std::string c = "string 1";
		std::string d = "string 2";
		std::cout << Y " a" C " = " G << c << C ", " Y "b" C " = " G << d << NC << std::endl << std::endl;
		swap(c, d); std::cout << B " swap" C "(" Y "a" C ", " Y "b" C ")" << std::endl << std::endl;
		std::cout << Y " a" C " = " G << c << C ", " Y "b" C " = " G << d << NC << std::endl << std::endl;
		std::cout << B " min" C "(" Y "a" C ", " Y "b" C ") = " G << min(c, d) << NC << std::endl;
		std::cout << B " max" C "(" Y "a" C ", " Y "b" C ") = " G << max(c, d) << NC << std::endl << std::endl;
	}
	std::cout << " =======================================" << std::endl << std::endl;
}
