/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:30:30 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/06 23:21:14 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

enum e_Types { _NOTHING, _CHAR, _INT, _FLOAT, _DOUBLE };

//  This function check the format of the literal. More than one decimal separator, non-digit in a number, etc...
static int isValid(std::string literal) {
    if (literal == "nan" || literal == "-nan" || literal == "inf" || literal == "+inf" || literal == "-inf") return (0);
    int DecimalPoint = 0;
    for (size_t i = 0; i < literal.length(); ++i) {
		if (i == 0 && (literal[i] == '+' || literal[i] == '-')) i++;
        if (literal[i] == '.')
			if (DecimalPoint) throw std::runtime_error("Invalid input"); else DecimalPoint = 1;
        else if (i == literal.length() - 1 && literal[i] == 'f') return (2);
		else if (!std::isdigit(literal[i])) throw std::runtime_error("Invalid input");
    }
    return (DecimalPoint);
}

void Converter::convert(std::string literal) {
    long double value = 0.0;
    int         Type = 0;
    bool        c_imp, i_imp; c_imp = i_imp = false;
    char        c;
    int         i;
    float       f;
    double      d;

    //  Trim spaces
	std::size_t k = 0;
    std::size_t j = literal.length();
    while (k < j && std::isspace(static_cast<unsigned char>(literal[k]))) ++k;
    while (j > k && std::isspace(static_cast<unsigned char>(literal[j - 1]))) --j;
    literal = literal.substr(k, j - k);
    if (literal.empty()) throw std::runtime_error("Invalid input");

    //  CHAR
    if (literal.length() == 1 && !std::isdigit(literal[0]) && std::isprint(literal[0])) {
        c = static_cast<char>(literal[0]);
        Type = _CHAR;

    //  FLOAT
    } else if (literal == "nanf" || literal == "-nanf" || literal == "inff" || literal == "+inff" || literal == "-inff" || isValid(literal) == 2) {
        if (literal == "nanf") { f = std::numeric_limits<float>::quiet_NaN(); c_imp = i_imp = true; }
        else if (literal == "-nanf") { f = -std::numeric_limits<float>::quiet_NaN(); c_imp = i_imp = true; }
        else if (literal == "inff" || literal == "+inff") { f = std::numeric_limits<float>::infinity(); c_imp = i_imp = true; }
        else if (literal == "-inff") { f = -std::numeric_limits<float>::infinity(); c_imp = i_imp = true; }
        else {
            std::istringstream iss(literal); iss >> value;  				//	Parses the string into a numeric value of type float
	        if (iss.fail()) throw std::runtime_error("Invalid input");		//	Throws an error if parsing the fails
            if (value > std::numeric_limits<float>::max() || value < std::numeric_limits<float>::min()) { d = static_cast<double>(value); Type = _DOUBLE;
            } else f = static_cast<float>(value);
        }
        if (Type == _NOTHING) Type = _FLOAT;

    //  DOUBLE
    } else if (literal == "nan" || literal == "-nan" || literal == "inf" || literal == "+inf" || literal == "-inf" || isValid(literal) == 1) {
        if (literal == "nan") { d = std::numeric_limits<double>::quiet_NaN(); c_imp = i_imp = true; }
        else if (literal == "-nan") { d = -std::numeric_limits<double>::quiet_NaN(); c_imp = i_imp = true; }
        else if (literal == "inf" || literal == "+inf") { d = std::numeric_limits<double>::infinity(); c_imp = i_imp = true; }
        else if (literal == "-inf") { d = -std::numeric_limits<double>::infinity(); c_imp = i_imp = true; }
        else {
            std::istringstream iss(literal); iss >> d;  					//	Parses the string into a numeric value of type double
    	    if (iss.fail()) throw std::runtime_error("Invalid input");		//	Throws an error if parsing the fails
        }
        Type = _DOUBLE;

    //  INT
    } else if (isValid(literal) == 0) {
        std::istringstream iss(literal); iss >> value;         				//	Parses the string into a numeric value of type int
	    if (iss.fail()) throw std::runtime_error("Invalid input"); 		    //	Throws an error if parsing the fails
        if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()) { d = static_cast<double>(value); Type = _DOUBLE;
        } else { i = static_cast<int>(value); Type = _INT; }
    }

    //  Cast away
    switch (Type) {
        case _CHAR:
            i = static_cast<int>(c);
            f = static_cast<float>(c);
            d = static_cast<double>(c); break;
        case _INT:
            c = static_cast<char>(i);
            f = static_cast<float>(i);
            d = static_cast<double>(i); break;
        case _FLOAT:
            c = static_cast<char>(f);
            i = static_cast<int>(f);
            d = static_cast<double>(f); break;
        case _DOUBLE:
            c = static_cast<char>(d);
            i = static_cast<int>(d);
            f = static_cast<float>(d); break;
        default: throw std::runtime_error("Invalid input");
    }

    //  CHAR
    if (c_imp ||i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
        std::cout << Y " Char:     " RD "impossible" NC << std::endl;
    else {
        if (std::isprint(c))
            std::cout << Y " Char:     " C << c << NC << std::endl;
        else
            std::cout << Y " Char:     " C "Non displayable" NC << std::endl;
    }

    //  INT
    if (i_imp || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        std::cout << Y " Int:      " RD "impossible" NC << std::endl;
    else
        std::cout << Y " Int:      " C << i << NC << std::endl;

    //  FLOAT
    std::cout << Y " Float:    " C << f;
	if (value == static_cast<long>(f)) std::cout << ".0";   //  The cast to long if to check if there is a decimal part, and add it if not
	std::cout << "f" NC << std::endl;

    //  DOUBLE
    std::cout << Y " Double:   " C << d;
    if (value == static_cast<long>(d)) std::cout << ".0";   //  The cast to long if to check if there is a decimal part, and add it if not
    std::cout << NC << std::endl;
}
