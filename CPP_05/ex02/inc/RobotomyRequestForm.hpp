/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:13:34 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/05 17:14:07 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
    
        std::string _target;

        RobotomyRequestForm();
        RobotomyRequestForm & operator=(const RobotomyRequestForm & rhs);

    public:

        RobotomyRequestForm(const std::string Target);
        RobotomyRequestForm(const RobotomyRequestForm & src);
        ~RobotomyRequestForm();
        
        std::string getTarget() const;
        void execute(const Bureaucrat & Executor) const;

};
