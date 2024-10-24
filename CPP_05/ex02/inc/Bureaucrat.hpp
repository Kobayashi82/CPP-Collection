/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:03:40 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/05 16:58:40 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>
# include "Colors.hpp"
# include "AForm.hpp"

class AForm;
class Bureaucrat {

	private:

		const std::string	_name;
		int 				_grade;

		Bureaucrat();
		const Bureaucrat & operator=(const Bureaucrat & rhs);

	public:

		Bureaucrat(const std::string Name, int Grade);
		Bureaucrat(const Bureaucrat & src);
		~Bureaucrat();

		std::string getName() const;
		int 		getGrade() const;

		void incGrade();
		void decGrade();
		void setGrade(int Grade);

		void signForm(AForm & cForm) const;
		void executeForm(const AForm & cForm) const;

		class GradeTooHighException : public std::exception { public: const char * what() const throw() { return ("Grade too high"); }};
		class GradeTooLowException : public std::exception { public: const char * what() const throw() { return ("Grade too low"); }};

};

std::ostream & operator<<(std::ostream & os, const Bureaucrat & rhs);
