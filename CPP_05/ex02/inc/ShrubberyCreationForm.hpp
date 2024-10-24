/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:13:45 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/05 17:14:01 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
    
        std::string _target;

        ShrubberyCreationForm();
        ShrubberyCreationForm & operator=(const ShrubberyCreationForm & rhs);

    public:

        ShrubberyCreationForm(const std::string Target);
        ShrubberyCreationForm(const ShrubberyCreationForm & src);
        ~ShrubberyCreationForm();
        
        std::string getTarget() const;
        void execute(const Bureaucrat & Executor) const;

};
