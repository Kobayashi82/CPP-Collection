/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:45:34 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/06 01:49:09 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//  Constructor (Private)

PresidentialPardonForm::PresidentialPardonForm() : AForm("Blank", 25, 5), _target("Blank") {}
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & rhs) { if (this != &rhs) { _target = rhs._target; } return (*this); }

//  Constructor (Public)

PresidentialPardonForm::PresidentialPardonForm(const std::string Target) : AForm("Presidential_Pardon", 25, 5), _target(Target) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & src) : AForm(src), _target(src._target) {}
PresidentialPardonForm::~PresidentialPardonForm() {}

//  Functions

std::string PresidentialPardonForm::getTarget() const { return (_target); }

void PresidentialPardonForm::execute(const Bureaucrat & Executor) const {
    if (Executor.getGrade() > this->getExecGrade()) throw GradeTooLowException();
    std::cout << Y << _target << C " has been pardoned by " G "Zaphod Beeblebrox" C " (reference to " Y "The Hitchhiker's Guide to the Galaxy" C ")" NC << std::endl;
}
