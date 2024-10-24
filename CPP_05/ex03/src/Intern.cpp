/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:25:39 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/17 07:24:20 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//  Constructor (Private)

Intern::Intern(const Intern & src) { *this = src; }
Intern & Intern::operator=( const Intern & rhs) { (void) rhs; return (*this); }

//  Constructor (Public)

Intern::Intern() {}
Intern::~Intern() {}

//  Functions

static AForm *createFormPresident(const std::string Target) { return (new PresidentialPardonForm(Target)); }
static AForm *createFormRobotomy(const std::string Target) { return (new RobotomyRequestForm(Target)); }
static AForm *createFormShrubbery(const std::string Target) { return (new ShrubberyCreationForm(Target)); }

AForm	*Intern::makeForm(std::string Name, std::string Target)
{
	AForm *Form = NULL;
	std::string Names[] = {"Presidential Pardon", "Robotomy Request", "Shrubbery Creation"};
	AForm * (*FormsCreator[])(std::string Target) = {&createFormPresident, &createFormRobotomy, &createFormShrubbery};
	try {
		for (size_t i = 0; i < (sizeof(Names) / sizeof(Names[0])); i++) {
			if (Name == Names[i]) { Form = FormsCreator[i](Target);	break; }
		}
		if (!Form) { std::cout << Y << Name << BR " does not exist in our list of " Y "Forms" << NC << std::endl; return (Form); }
		std::cout << Y << Form->getName() << BR " created   \t(" B "unsigned" BR ")" G "\t  ReqGrade" BR " = " B << Form->getReqGrade() << "    \t" G "ExecGrade" BR " = " B << Form->getExecGrade() << NC << std::endl;
		return (Form);
	} catch(const std::exception & e) {
		std::cout << Y << Form->getName() << BR " created   \t(" B "unsigned" BR ")" G "\t  ReqGrade" BR " = " B << Form->getReqGrade() << "    \t" G "ExecGrade" BR " = " B << Form->getExecGrade() << RD "\t   ERROR: " Y << e.what() << NC << std::endl;
		if (Form) delete Form; return (NULL);
	}
}
