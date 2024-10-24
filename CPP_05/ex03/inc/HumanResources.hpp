/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanResources.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:14:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/05 18:23:50 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Colors.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

enum e_FormType {
	PresidentialPardon,
	RobotomyRequest,
	ShrubberyCreation
};

Bureaucrat * HireEmployee(const std::string Name, int Grade);
void FireEmployee(Bureaucrat ** Employee);
void SetGrade(Bureaucrat * Employee, int NewGrade);
void IncGrade(Bureaucrat * Employee);
void DecGrade(Bureaucrat * Employee);

AForm * CreateForm(e_FormType Type, std::string Target);
void DestroyForm(AForm ** Form);
void SignForm(AForm * form, Bureaucrat * Employee);
void ExecuteForm(AForm * form, Bureaucrat * Employee);
