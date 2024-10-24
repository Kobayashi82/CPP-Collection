/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:03:40 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/05 16:11:47 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>
# include "Colors.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;
class AForm {

	private:

		const std::string	_name;
		bool				_signed;
		const int			_req_grade;
		const int			_exec_grade;

		AForm();
		const AForm & operator=(const AForm & rhs);

	public:

		AForm(const std::string Name, int ReqGrade, int ExecGrade);
		AForm(const AForm & src);
		virtual ~AForm();

		std::string getName() const;
		bool 		getSigned() const;
		int 		getReqGrade() const;
		int 		getExecGrade() const;

		void beSigned(const Bureaucrat & Employee);
		virtual void execute(const Bureaucrat & Executor) const = 0;

		class GradeTooHighException : public std::exception { public: const char * what() const throw() { return ("Grade too high"); }};
		class GradeTooLowException : public std::exception { public: const char * what() const throw() { return ("Grade too low"); }};
		class FormNotSignException : public std::exception { public: const char * what() const throw() { return ("Form not signed"); }};

};

std::ostream & operator<<(std::ostream & os, const AForm & rhs);
