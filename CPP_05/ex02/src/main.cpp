/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 20:13:05 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Colors.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "HumanResources.hpp"

int main() {
	std::cout << std::endl << " ======================================" << std::endl << std::endl
			  << BR " Here we complicate the situation further." << std::endl << std::endl
			  << " Now the " Y "Form" BR " class is an " G "abstract class" BR "." << std::endl << std::endl
			  << " we have " G "derived classes" BR " from it that have certain " B "peculiarities" BR "." << std::endl << std::endl
			  << " And " B "bureaucrats" BR " can " G "execute " Y "Forms" BR " in addition to " G "signing" BR " them." << std::endl
			  << " Of course, a " Y "Form" BR " must be " G "signed" BR " to be " G "executed" BR "."<< std::endl << std::endl
			  << " These exercises help us practice with " B "classes" BR " and their interactions among them, while also" << std::endl
			  << " allowing us to become familiar with " RD "exceptions" BR "." NC << std::endl << std::endl;
	{
		//	HUMAN RESOURCES TESTS

		std::cout <<   " ======================================" << std::endl
				  << G "         HUMAN RESOURCES TESTS         " NC << std::endl 
				  <<   " ======================================" << std::endl << std::endl;

		std::string		Employee_Name;
		AForm *			Forms[5];
		Bureaucrat *	Employees[5];
		
		Forms[0] = CreateForm(PresidentialPardon, "vzurera-");
		Forms[1] = CreateForm(RobotomyRequest, "the boss's friend");
		Forms[2] = CreateForm(ShrubberyCreation, "random guy");
		Forms[3] = CreateForm(RobotomyRequest, "useless kid");
		Forms[4] = CreateForm(PresidentialPardon, "serial killer");
 		std::cout << std::endl << " ——————————————————————————————————————" NC << std::endl << std::endl;

		Employees[0] = HireEmployee("the boss's friend", 120);
		Employees[1] = HireEmployee("vzurera-", 42);
		Employees[2] = HireEmployee("useless kid", 150);
		Employees[3] = HireEmployee("random guy", 999);
		Employees[4] = HireEmployee("genius kid", 1);
		std::cout << std::endl << std::endl << " ———————————— " G "SIGN FORMS" NC " ——————————————" << std::endl << std::endl;

		SignForm(Forms[0], Employees[0]);
		SignForm(Forms[1], Employees[1]);
		SignForm(Forms[2], Employees[2]);
		SignForm(Forms[3], Employees[3]);
		SignForm(Forms[4], Employees[4]);
		std::cout << std::endl << " ———————————— " G "EXEC FORMS" NC " ——————————————" << std::endl << std::endl;

		ExecuteForm(Forms[0], Employees[0]);
		ExecuteForm(Forms[1], Employees[1]);
		ExecuteForm(Forms[2], Employees[2]);
		ExecuteForm(Forms[3], Employees[3]);
		ExecuteForm(Forms[4], Employees[4]);
		std::cout << std::endl << " ———————————— " G "SIGN FORMS" NC " ——————————————" << std::endl << std::endl;

		SignForm(Forms[0], Employees[4]);
		SignForm(Forms[2], Employees[4]);
		std::cout << std::endl << " ———————————— " G "EXEC FORMS" NC " ——————————————" << std::endl << std::endl;
	
		ExecuteForm(Forms[2], Employees[0]);
		ExecuteForm(Forms[0], Employees[4]);
		std::cout << std::endl << " ——————————————————————————————————————" NC << std::endl << std::endl;

		for (int i = 0; i < 5; i++) DestroyForm (&Forms[i]);
		std::cout << std::endl;
		for (int i = 0; i < 5; i++) FireEmployee (&Employees[i]);
		std::cout << std::endl;
	}
	std::cout << " =======================================" << std::endl << std::endl;
	std::cout << RD " The company has gone bankrupt due to lack of qualified personnel" NC << std::endl << std::endl;
}
