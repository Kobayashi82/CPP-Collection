/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 20:05:46 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Bureaucrat.hpp"
#include "HumanResources.hpp"
#include <iostream>

int main() {
	std::cout << std::endl << " ======================================" << std::endl << std::endl
			  << BR " In this " C "exercise" BR ", a " B "class" BR " is created where we have an " Y "employee" BR " with a " G "name" BR " and " G "grade" BR "," << std::endl
			  << " their " G "getters" BR ", a " G "setter" BR " (only for the "G "grade" BR ") and two methods to " G "promote" BR " or " G "demote" BR " a " Y "employee" BR "." << std::endl << std::endl
			  << " We also see how " RD "errors" BR " or " RD "exceptions" BR " work. Which can end the current " G "execution" BR " of a function" << std::endl
			  << " and redirect it to the appropriate " B "catch" BR "." << std::endl << std::endl
			  << " The use of " RD "exceptions" BR " is a way to have safe and robust code." << std::endl << std::endl
			  << " In the following " C "tests" BR ", " Y "employees" BR " are created, assigned a " G "grade" BR ", " G "promoted" BR " or " G "demoted" BR ", and " << std::endl
			  << " finally " G "dismissed" BR "." << std::endl << std::endl
			  << " The hiring of " Y "employees" BR " is done by a function that returns a " B "pointer" BR " to the created " B "object" BR " and" << std::endl
			  << " after the corresponding " C "tests" BR ", the " Y "employee" BR " is " G "dismissed" BR " by releasing the " B "object" BR " and setting" << std::endl
			  << " the " B "variable" BR " to " B "NULL" BR "." NC << std::endl << std::endl;
	{
		//	HUMAN RESOURCES TESTS

		std::cout << " ======================================" << std::endl
				  << G "\t HUMAN RESOURCES TESTS" NC
				  << std::endl << " ======================================" << std::endl << std::endl;

		std::string		Employee_Name;
		Bureaucrat *	Employee = NULL;
		
		Employee_Name = "intern";
		if ((Employee = HireBureaucrat(Employee_Name, 140))) {
			SetGrade(Employee, 145); IncGrade(Employee); DecGrade(Employee); FireBureaucrat(&Employee);
		} std::cout << std::endl << std::endl << " ——————————————————————————————————————" NC << std::endl << std::endl;

		Employee_Name = "the boss's friend";
		if ((Employee = HireBureaucrat(Employee_Name, 150))) {
			SetGrade(Employee, 1); IncGrade(Employee); DecGrade(Employee); FireBureaucrat(&Employee);
		} std::cout << std::endl << std::endl << " ——————————————————————————————————————" NC << std::endl << std::endl;

		Employee_Name = "vzurera-";
		if ((Employee = HireBureaucrat(Employee_Name, 20))) {
			SetGrade(Employee, 200); SetGrade(Employee, 0); SetGrade(Employee, 1);
			DecGrade(Employee); IncGrade(Employee); FireBureaucrat(&Employee);
		} std::cout << std::endl << std::endl << " ——————————————————————————————————————" NC << std::endl << std::endl;

		Employee_Name = "useless kid";
		if ((Employee = HireBureaucrat(Employee_Name, 999))) {
			SetGrade(Employee, 200); SetGrade(Employee, 0); SetGrade(Employee, 1);
			DecGrade(Employee); IncGrade(Employee); FireBureaucrat(&Employee);
		} std::cout << std::endl << std::endl << " ——————————————————————————————————————" NC << std::endl << std::endl;

		Employee_Name = "genius kid";
		if ((Employee = HireBureaucrat(Employee_Name, -999))) {
			SetGrade(Employee, 200); SetGrade(Employee, 0); SetGrade(Employee, 1);
			DecGrade(Employee); IncGrade(Employee); FireBureaucrat(&Employee);
		} std::cout << std::endl << std::endl << " ——————————————————————————————————————" NC << std::endl << std::endl;

		Employee_Name = "random guy";
		if ((Employee = HireBureaucrat(Employee_Name, 50))) {
			SetGrade(Employee, 150); DecGrade(Employee); IncGrade(Employee); FireBureaucrat(&Employee);
		} std::cout << std::endl;

	}
	std::cout << " =======================================" << std::endl << std::endl;
	std::cout << RD " The company has gone bankrupt due to lack of qualified personnel" NC << std::endl << std::endl;
}
