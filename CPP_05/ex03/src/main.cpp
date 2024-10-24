/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 20:16:12 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Colors.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "HumanResources.hpp"

int main() {
	std::cout << std::endl << " ======================================" << std::endl << std::endl
			  << BR " In this last exercise, we are asked to create a " B "class" BR " that, given the " G "Name" BR " of a " Y "Form" BR " and " << std::endl
			  << " the " G "Target" BR " of that " Y "Form" BR ", it creates the corresponding " Y "Form" BR " object." << std::endl << std::endl
			  << " It's something I had already implemented in the " B "Human Resources" BR " class, so it wasn't" << std::endl
			  << " very complicated." << std::endl << std::endl
			  << G " Thank you for evaluating me." NC << std::endl << std::endl;
	{
		//	HUMAN RESOURCES TESTS

		std::cout <<   " ======================================" << std::endl
				  << G "         HUMAN RESOURCES TESTS         " NC << std::endl 
				  <<   " ======================================" << std::endl << std::endl;

		std::string		Employee_Name;
		AForm *			Forms[5];
		Bureaucrat *	Employees[5];
		Intern			InternGuy;		
		
		Forms[0] = InternGuy.makeForm("Presidential Pardon", "vzurera-");
		Forms[1] = InternGuy.makeForm("Robotomy Request", "the boss's friend");
		Forms[2] = InternGuy.makeForm("Random Form", "vzurera-");
		Forms[2] = InternGuy.makeForm("Shrubbery Creation", "random guy");
		Forms[3] = InternGuy.makeForm("Robotomy Request", "useless kid");
		Forms[4] = InternGuy.makeForm("Presidential Pardon", "serial killer");
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
