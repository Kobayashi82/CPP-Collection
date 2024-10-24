/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:30:42 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/05 18:53:47 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime> 
#include <cstdlib>
#include "RobotomyRequestForm.hpp"

//  Constructor (Private)

RobotomyRequestForm::RobotomyRequestForm() : AForm("Blank", 72, 45), _target("Blank") { srand(static_cast<unsigned int>(time(0))); }
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & rhs) { if (this != &rhs) { _target = rhs._target; } return (*this); }

//  Constructor (Public)

RobotomyRequestForm::RobotomyRequestForm(const std::string Target) : AForm("Robotomy_Request", 72, 45), _target(Target) { srand(static_cast<unsigned int>(time(0))); }
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & src) : AForm(src), _target(src._target) { srand(static_cast<unsigned int>(time(0))); }
RobotomyRequestForm::~RobotomyRequestForm() {}

//  Functions

std::string RobotomyRequestForm::getTarget() const { return (_target); }

void RobotomyRequestForm::execute(const Bureaucrat & Executor) const {
    if (Executor.getGrade() > this->getExecGrade()) throw GradeTooLowException();
     std::cout << C "Brrrrrrrrr... Brrrrrrrrr...   ";
    if (rand() % 2)
       std::cout << Y << _target << C " has been robotomized successfully" NC << std::endl;
    else
        std::cout << C "The robotomy on " Y << _target << C " failed." NC << std::endl;
}
