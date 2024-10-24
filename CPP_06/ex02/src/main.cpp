/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 20:33:52 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include <iostream>
#include <cstdlib>

class Base { public: virtual ~Base() {} };

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base * generate() {
	switch (std::rand() % 4) {
		case 0: return (new A());
		case 1: return (new B());
		case 2: return (new C());
		default: return (NULL);
	}
}

void identify(Base & p) {
    if (dynamic_cast<A*>(&p) != NULL)
        std::cout << CY " The object passed as " BL "reference" CY " is " Y "A"   NC << std::endl;
    else if (dynamic_cast<B*>(&p) != NULL)
        std::cout << CY " The object passed as " BL "reference" CY " is " Y "B"   NC << std::endl;
    else if (dynamic_cast<C*>(&p) != NULL)
        std::cout << CY " The object passed as " BL "reference" CY " is " Y "C"   NC << std::endl;
    else
        std::cout << CY " The object passed as " BL "reference" CY " is " RD "Unkown" NC << std::endl;
}

void identify(Base * p) {
	if 		(dynamic_cast<A*>(p)) std::cout << CY " The object passed as " BL "pointer" CY "   is " Y "A"		NC << std::endl;
	else if (dynamic_cast<B*>(p)) std::cout << CY " The object passed as " BL "pointer" CY "   is " Y "B"		NC << std::endl;
	else if (dynamic_cast<C*>(p)) std::cout << CY " The object passed as " BL "pointer" CY "   is " Y "C"		NC << std::endl;
	else 						  std::cout << CY " The object passed as " BL "pointer" CY "   is " RD "Unkown" NC << std::endl;
}

int main() {
	srand(time(0));
	std::cout << std::endl << " ======================================" << std::endl << std::endl
			  << BR " In this last exercise, we are required to use " BL "dynamic_cast" BR " to perform " Y "type" BR " identification" << std::endl
			  << " between" BL " pointers" BR " and " BL "references" BR " within an " G "inheritance" BR " hierarchy." << std::endl << std::endl
			  << " We are not allowed to use " Y "typeinfo" BR", which is a " G "header" BR " that provides information about the " Y "type" BR << std::endl
			  << " of an object during " BL "run-time" BR "." << std::endl << std::endl
			  << " In the test, we iterates 10 times creating a " G "random" BR " class and calling the functions that identify" << std::endl
			  << " the " Y "type" BR " of class based on whether it is a " BL "pointer" BR " or a " BL "reference" BR "." << std::endl << std::endl
			  << " Finally we free the " BL "object" BR "." << std::endl << std::endl
			  << G " Thank you for evaluating me." NC << std::endl << std::endl;
	{
		std::cout <<   " ======================================" << std::endl
				  << G "             IDENTIFY TESTS            " NC << std::endl
				  <<   " ======================================" << std::endl << std::endl;

		Base * p;
		
		for (int i = 0; i < 10; i++) {
			p = generate(); identify(p); identify(*p);
			delete p; std::cout << std::endl;
		}
	}
	std::cout << " =======================================" << std::endl << std::endl;
}
