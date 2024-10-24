/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:45:38 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/05 17:14:16 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
    
        std::string _target;

        PresidentialPardonForm();
        PresidentialPardonForm & operator=(const PresidentialPardonForm & rhs);

    public:

        PresidentialPardonForm(const std::string Target);
        PresidentialPardonForm(const PresidentialPardonForm & src);
        ~PresidentialPardonForm();
        
        std::string getTarget() const;
        void execute(const Bureaucrat & Executor) const;

};
