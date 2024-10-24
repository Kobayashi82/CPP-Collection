/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:03:37 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/04 18:01:35 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//	Constructors (Private)

AForm::AForm() : _name("Blank"), _signed(false), _req_grade(150), _exec_grade(150) {}
const AForm & AForm::operator=(const AForm & rhs) { _signed = rhs._signed; return (*this); }

//	Constructors (Public)

AForm::AForm(const std::string Name, int ReqGrade, int ExecGrade) : _name(Name), _signed(false), _req_grade(ReqGrade), _exec_grade(ExecGrade) {
	if (_req_grade < 1 || _exec_grade < 1) throw GradeTooHighException();
	if (_req_grade > 150 || _exec_grade > 150) throw GradeTooLowException();
}
AForm::AForm(const AForm & src) : _name(src._name), _signed(src._signed), _req_grade(src._req_grade), _exec_grade(src._exec_grade) {}
AForm::~AForm() {}

//	Functions

std::string AForm::getName() const { return (_name); }
bool		AForm::getSigned() const { return (_signed); }
int 		AForm::getReqGrade() const { return (_req_grade); }
int 		AForm::getExecGrade() const { return (_exec_grade); }

void		AForm::beSigned(const Bureaucrat & Employee) {
	if (Employee.getGrade() > _req_grade) throw GradeTooLowException();
	_signed = true;
}

//	Overloads

std::ostream & operator<<(std::ostream & os, const AForm & rhs) {
	if (rhs.getSigned())
		os << Y << rhs.getName() << C " is " G "signed" C ". The required grade to sign it was " Y << rhs.getReqGrade() << C " and to execute it is " Y << rhs.getExecGrade() << NC;
	else
		os << Y << rhs.getName() << C " is " RD "unsigned" C ". The required grade to sign it is " Y << rhs.getReqGrade() << C " and to execute it is " Y << rhs.getExecGrade() << NC;
	return (os);
}
