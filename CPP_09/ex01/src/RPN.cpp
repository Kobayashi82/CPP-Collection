/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:10:50 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/10 14:51:39 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static int calculate(int a, int b, char operators) {																						//	Performs the operation and returns the result
	if (operators == '-') return (a - b);
	if (operators == '+') return (a + b);
	if (operators == '*') return (a * b);
	if (operators == '/' && b == 0) throw std::runtime_error("Can't divide by 0");															//	Can't divide by 0
	if (operators == '/') return (a / b);
	throw std::runtime_error("Invalid expression");																							//	If it gets here, throw an error
}

void RPN(std::string literal) {
	std::stack <int>	Pool;																												//	Declare stack container
	int					a, b;
	bool				remove = false;																										//	Declare variables

	try {

		for (size_t i = 0; i < literal.size(); ++i) {
			if (std::isspace(literal[i])) { if (!remove) { remove = true; continue ; } else { literal.erase(i, 1); i--; continue ; }}		//	Remove repeated spaces
			remove = false;

			if (!std::isdigit(literal[i]) && std::string("+-*/").find(literal[i]) == std::string::npos)										//	If it's not a digit or operator, throw an error
				throw std::runtime_error("Invalid expression");

			if (std::isdigit(literal[i])) {
				if (!std::isspace(literal[i + 1]) && std::string("+-*/").find(literal[i + 1]) == std::string::npos)							//	Only digit + (space or operator) is allowed
					throw std::runtime_error("Invalid expression");
				Pool.push(literal[i] - '0');																								//	Add the digit to the stack
			}

			if (std::string("+-*/").find(literal[i]) != std::string::npos) {
				if (!std::isdigit(literal[i + 1]) && !std::isspace(literal[i + 1]) && std::string("+-*/").find(literal[i + 1]) == std::string::npos)	// Only operator + (space or digit or operator) is allowed
					throw std::runtime_error("Invalid expression");
				if (Pool.size() < 2) throw std::runtime_error("Invalid expression");														//	There must be at least two elements in the stack to operate
				b = Pool.top(); Pool.pop();																									//	Take out the first element
				a = Pool.top(); Pool.pop();																									//	Take out the second element
				Pool.push(calculate(a, b, literal[i]));																						//	Perform the operation and store the result in the stack
			}

		}
		if (Pool.empty() || Pool.size() > 1) throw std::runtime_error("Invalid expression");												//	If the stack is empty or has more than one element, throw an error
		if (std::isspace(literal[0])) literal.erase(0, 1);																					//	Remove leading spaces
		if (std::isspace(literal[literal.size() - 1])) literal.erase(literal.size() - 1, 1);												//	Remove trailing spaces
		std::cout << C " The result of the expression:" << std::endl << std::endl;
		std::cout << Y " " << literal << C " is " G << Pool.top() << NC << std::endl;														//	Display the result
	} catch (std::exception & e) {
		std::cerr << RD " Error: " Y << e.what() << NC << std::endl;																		//	Display an error message
	}
}
