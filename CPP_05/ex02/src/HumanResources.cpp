/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanResources.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:14:21 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/17 07:14:11 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanResources.hpp"

//	EMPLOYEES

Bureaucrat * HireEmployee(const std::string Name, int Grade) {
	Bureaucrat * Employee = NULL;
	try {
		Employee = new Bureaucrat(Name, Grade);
		std::cout << B " Newly hired employee \t" << *Employee << std::endl;
		return (Employee);
	} catch(const std::exception & e) {
		std::cout << B " Newly hired employee \t" << Y << Name << C ", bureaucrat grade " G << Grade << C "." << std::endl;
		std::cout << B " Starting grade " G << Grade << B "\t" RD "We cannot hire you, sorry" << "\t\t\t   ERROR: " Y << e.what() << NC << std::endl;
		if (Employee) delete Employee; return (NULL);
	}
}

void FireEmployee(Bureaucrat ** Employee) {
	if (*Employee) {
		std::cout << Y " " << (*Employee)->getName() << B " has been fired for incompetence" NC << std::endl;
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

//	FORMS

AForm * CreateForm(e_FormType Type, std::string Target) {
	AForm * form = NULL;
	try {
		switch (Type) {
			case PresidentialPardon: form = new PresidentialPardonForm(Target); break;
			case RobotomyRequest: form = new RobotomyRequestForm(Target); break;
			case ShrubberyCreation: form = new ShrubberyCreationForm(Target); break;
			default: return (NULL);
		}
		std::cout << Y << form->getName() << BR " created   \t(" B "unsigned" BR ")" G "\t  ReqGrade" BR " = " B << form->getReqGrade() << "    \t" G "ExecGrade" BR " = " B << form->getExecGrade() << NC << std::endl;
		return (form);
	} catch(const std::exception & e) {
		std::cout << Y << form->getName() << BR " created   \t(" B "unsigned" BR ")" G "\t  ReqGrade" BR " = " B << form->getReqGrade() << "    \t" G "ExecGrade" BR " = " B << form->getExecGrade() << RD "\t   ERROR: " Y << e.what() << NC << std::endl;
		if (form) delete form; return (NULL);
	}
}

void DestroyForm(AForm ** Form) {
	if (*Form) {
		std::cout << Y " " << (*Form)->getName() << B " has been destroyed... forever" NC << std::endl;
		delete *Form; *Form = NULL;
	}
}

void SignForm(AForm * form, Bureaucrat * Employee) {
	if (form && Employee) {
		Employee->signForm(*form);
		std::cout << *form << std::endl << std::endl;
	}
}

void ExecuteForm(AForm * form, Bureaucrat * Employee) {
	if (form && Employee) {
		Employee->executeForm(*form);
		std::cout << std::endl;
	}
}
