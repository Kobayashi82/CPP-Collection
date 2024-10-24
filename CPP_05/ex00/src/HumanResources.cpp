/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanResources.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:14:21 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/04 19:33:50 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanResources.hpp"

Bureaucrat * HireBureaucrat(const std::string Name, int Grade) {
	Bureaucrat * Employee = NULL;
	try {
		Employee = new Bureaucrat(Name, Grade);
		std::cout << B " Newly hired employee \t" << *Employee << std::endl << std::endl;
		return (Employee);
	}
	catch(const std::exception & e) {
		std::cout << B " Newly hired employee \t" << Y << Name << C ", bureaucrat grade " G << Grade << C "." << std::endl << std::endl;
		std::cout << B " Starting grade " G << Grade << B "\t" RD "ERROR: " Y << e.what() << NC << std::endl << std::endl;
		std::cout << B " We cannot hire you, sorry" NC << std::endl;
		if (Employee) delete Employee; return (NULL);
	}
}

void FireBureaucrat(Bureaucrat ** Employee) {
	if (*Employee) {
		std::cout << std::endl << Y " " << (*Employee)->getName() << B " has been fired for incompetence" NC << std::endl;
		delete *Employee; *Employee = NULL;
	}
}

void SetGrade(Bureaucrat * Employee, int NewGrade) {
	try { Employee->setGrade(NewGrade); std::cout << B " Set grade to " G << NewGrade << "  \t" << *Employee << std::endl; }
	catch(const std::exception & e) { std::cout << B " Set grade to " G << NewGrade << "  \t" RD "ERROR: " Y << e.what() << NC << std::endl; }
}

void IncGrade(Bureaucrat * Employee) {
	try { Employee->incGrade(); std::cout << B " Promote employee " G << "  \t" << *Employee << std::endl; }
	catch(const std::exception & e) { std::cout << B " Promote employee " G << "\t" << RD "ERROR: " Y << e.what() << NC << std::endl; }
}

void DecGrade(Bureaucrat * Employee) {
	try { Employee->decGrade(); std::cout << B " Demote employee " G << "  \t" << *Employee << std::endl; }
	catch(const std::exception & e) { std::cout << B " Demote employee " G << "\t" << RD "ERROR: " Y << e.what() << NC << std::endl; }
}
