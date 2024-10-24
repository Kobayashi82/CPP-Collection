/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanResources.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:14:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 20:05:53 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Colors.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat * HireEmployee(const std::string Name, int Grade);
void FireEmployee(Bureaucrat ** Employee);
void SetGrade(Bureaucrat * Employee, int NewGrade);
void IncGrade(Bureaucrat * Employee);
void DecGrade(Bureaucrat * Employee);

Form * CreateForm(const std::string Name, int ReqGrade, int ExecGrade);
void DestroyForm(Form ** Form);
void SignForm(Form * form, Bureaucrat * Employee);
