/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:03:40 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 20:05:12 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "Colors.hpp"
# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;
class Form {

	private:

		const std::string	_name;
		bool				_signed;
		const int			_req_grade;
		const int			_exec_grade;

		Form();
		const Form & operator=(const Form & rhs);

	public:

		Form(const std::string Name, int ReqGrade, int ExecGrade);
		Form(const Form & src);
		~Form();

		std::string getName() const;
		bool 		getSigned() const;
		int 		getReqGrade() const;
		int 		getExecGrade() const;

		void beSigned(const Bureaucrat & Employee);

		class GradeTooHighException : public std::exception { public: const char * what() const throw() { return ("Grade too high"); }};
		class GradeTooLowException : public std::exception { public: const char * what() const throw() { return ("Grade too low"); }};

};

std::ostream & operator<<(std::ostream & os, const Form & rhs);
