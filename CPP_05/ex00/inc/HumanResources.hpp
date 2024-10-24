/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanResources.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:14:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 20:05:36 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Colors.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat * HireBureaucrat(const std::string Name, int Grade);
void FireBureaucrat(Bureaucrat ** Employee);
void SetGrade(Bureaucrat * Employee, int NewGrade);
void IncGrade(Bureaucrat * Employee);
void DecGrade(Bureaucrat * Employee);
