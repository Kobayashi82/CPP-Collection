/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:03:40 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 20:05:30 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Colors.hpp"
#include <iostream>


class Bureaucrat {

	private:

		const std::string	_name;
		int 				_grade;

		//	We cannot modify _name because it is a constant. We could only modify _grade, but in this case,
		//	it would be expected to copy the complete information and not just a part.
		//	Therefore, it is better not to allow copying.
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
		void setGrade(int Grade);	//	This is not required.

		// Here we declare the exceptions. These can be thrown with 'throw' and caught in a 'try-catch' block.
		class GradeTooHighException : public std::exception { public: const char * what() const throw() { return ("Grade too high"); }};
		class GradeTooLowException : public std::exception { public: const char * what() const throw() { return ("Grade too low"); }};

};

std::ostream & operator<<(std::ostream & os, const Bureaucrat & rhs);
