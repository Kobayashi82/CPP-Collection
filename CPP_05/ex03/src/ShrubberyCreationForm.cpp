/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:29:25 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/06 01:49:15 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

//  Constructor (Private)

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Blank", 145, 137), _target("Blank") {}
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & rhs) { if (this != &rhs) { _target = rhs._target; } return (*this); }

//  Constructor (Public)

ShrubberyCreationForm::ShrubberyCreationForm(const std::string Target) : AForm("Shrubbery_Creation", 145, 137), _target(Target) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & src) : AForm(src), _target(src._target) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

//  Functions

std::string ShrubberyCreationForm::getTarget() const { return (_target); }

void ShrubberyCreationForm::execute(const Bureaucrat & Executor) const {
    if (Executor.getGrade() > this->getExecGrade()) throw GradeTooLowException();
    std::ofstream file((this->getName() + "_shrubbery").c_str());
    file << "             ,@@@@@@@,"                        << std::endl
         << "            ,@@@@@@/@@, .oo8888o."             << std::endl
         << "  ,%%&%&&%,@@@@@/@@@@@@,8888\\88/8o"           << std::endl
         << " ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'"       << std::endl
         << " %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'"        << std::endl
         << " %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'"         << std::endl
         << " `&%\\ ` /%&'    |.|        | '/8'"            << std::endl
         << "     |o|        | |        | |"                << std::endl
         << "     |.|        | |        |o|"                << std::endl
         << "____/ ._\\______/  ,\\______/.  \\________"    << std::endl;
    file.close();
    std::cout << Y << _target << C " has planted a " G "tree" C " on your disk" NC << std::endl;
}
