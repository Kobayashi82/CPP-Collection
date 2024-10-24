/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 20:05:59 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "HumanResources.hpp"
#include <iostream>

int main() {
	std::cout << std::endl << " ======================================" << std::endl << std::endl
			  << BR " In this second exercise I have created a second " B "class" BR " called " Y "Form" BR " with some requirements" << std::endl
			  << " that a " G "bureaucrat" BR " must meet in order to " G "sign" BR " it." << std::endl << std::endl
			  << " There's not much more to it, just interacting with different " B "classes" BR " and handling" << std::endl
			  << " the " RD "exceptions" BR " that may occur." << std::endl << std::endl
			  << " I have modified " Y "Human Resources" BR " so that it can manage the " Y "Forms" BR " and improved the creation" << std::endl
			  << " and destruction of the " B "objects" BR "." << std::endl << std::endl
			  << " The " G "execution" BR " requirements of the " Y "Forms" BR " are used in the next exercise." NC << std::endl << std::endl;
	{
		//	HUMAN RESOURCES TESTS

		std::cout <<   " ======================================" << std::endl
				  << G "         HUMAN RESOURCES TESTS         " NC << std::endl 
				  <<   " ======================================" << std::endl << std::endl;

		std::string		Employee_Name;
		Form *			Forms[5];
		Bureaucrat *	Employees[5];
		
		Forms[0] = CreateForm("FormA", 100, 90);
		Forms[1] = CreateForm("FormB", 42, 50);
		Forms[2] = CreateForm("FormC", 1, 1);
		Forms[3] = CreateForm("FormD", 500, 50);
		Forms[4] = CreateForm("FormE", 150, 150);
 		std::cout << std::endl << std::endl << " ——————————————————————————————————————" NC << std::endl << std::endl;

		Employees[0] = HireEmployee("the boss's friend", 120);
		Employees[1] = HireEmployee("vzurera-", 42);
		Employees[2] = HireEmployee("useless kid", 150);
		Employees[3] = HireEmployee("random guy", 999);
		Employees[4] = HireEmployee("genius kid", 1);
		std::cout << std::endl << std::endl << " ——————————————————————————————————————" NC << std::endl << std::endl;

		SignForm(Forms[0], Employees[0]);
		SignForm(Forms[1], Employees[1]);
		SignForm(Forms[2], Employees[2]);
		SignForm(Forms[3], Employees[3]);
		SignForm(Forms[4], Employees[4]);
		std::cout << std::endl << " ——————————————————————————————————————" NC << std::endl << std::endl;

		for (int i = 0; i < 5; i++) DestroyForm (&Forms[i]);
		std::cout << std::endl;
		for (int i = 0; i < 5; i++) FireEmployee (&Employees[i]);
		std::cout << std::endl;
	}
	std::cout << " =======================================" << std::endl << std::endl;
	std::cout << RD " The company has gone bankrupt due to lack of qualified personnel" NC << std::endl << std::endl;
}
