/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:03:37 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/17 07:15:14 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//	Constructors (Private)

Bureaucrat::Bureaucrat() : _name(""), _grade(150) {}
const Bureaucrat & Bureaucrat::operator=(const Bureaucrat & rhs) { if (this != &rhs) { _grade = rhs._grade;} return (*this); }

//	Constructors (Public)

Bureaucrat::Bureaucrat(const std::string Name, int Grade) : _name(Name), _grade(Grade) {
	if (_grade < 1) throw GradeTooHighException();
	if (_grade > 150) throw GradeTooLowException();
}
Bureaucrat::Bureaucrat(const Bureaucrat & src) : _name(src._name), _grade(src._grade) {
	if (_grade < 1) throw GradeTooHighException();
	if (_grade > 150) throw GradeTooLowException();
}
Bureaucrat::~Bureaucrat() {}

//	Functions

std::string Bureaucrat::getName() const { return (_name); }
int			Bureaucrat::getGrade() const { return (_grade); }

void Bureaucrat::incGrade() { if (_grade - 1 < 1) throw GradeTooHighException(); else _grade--; }
void Bureaucrat::decGrade() { if (_grade + 1 > 150) throw GradeTooLowException(); else _grade++; }
void Bureaucrat::setGrade(int Grade) {
	if (Grade < 1) throw GradeTooHighException();
	if (Grade > 150) throw GradeTooLowException();
	_grade = Grade;
}

void Bureaucrat::signForm(Form & form) {
	try {
		form.beSigned(*this);
		std::cout << Y << _name << C " with grade " G << _grade << C " signed " Y << form.getName() << NC << std::endl;
	} catch (std::exception & e) {
		std::cout << Y << _name << C " with grade " G << _grade << C " couldn't sign " Y << form.getName() << C " because have a " RD << e.what() << NC << std::endl;
	}
}

//	Overloads

std::ostream & operator<<(std::ostream & os, const Bureaucrat & rhs) { os << Y << rhs.getName() << C ", bureaucrat grade " G << rhs.getGrade() << NC; return (os); }
