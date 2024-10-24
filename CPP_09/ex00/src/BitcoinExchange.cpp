/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:19:38 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 21:38:23 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//	********* VALIDATE DATE *********

static bool isLeapYear(int year) { return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);}						//	A year is leap if it is divisible by 4 but not by 100, unless it is also divisible by 400

static int daysInMonth(int year, int month) {																			//	Determine the number of days in a month
    switch (month) {
        case 4: case 6: case 9: case 11: return (30);
        case 2: if (isLeapYear(year)) return (29); else return (28);
        default: return (31);
    }
}

static void validateDate(std::string & Date) {																			//	Validate a Date as string
    std::size_t k = 0; std::size_t j = Date.length();
    while (k < j && std::isspace(Date[k])) ++k;																			//	Remove leading and trailing spaces
    while (j > k && std::isspace(Date[j - 1])) --j;
    Date = Date.substr(k, j - k);

    if (Date.empty()) throw std::runtime_error("There is no date.");
    if (Date.length() != 10 || Date[4] != '-' || Date[7] != '-') throw std::runtime_error("Not a valid date " C "=> " RD + Date);

    std::istringstream	year_ss(Date.substr(0, 4));
    std::istringstream	month_ss(Date.substr(5, 2));
    std::istringstream	day_ss(Date.substr(8, 2));
    int					year, month, day;																				//	Declare variables

    year_ss >> year; month_ss >> month; day_ss >> day;																			//	Convert date values to integers
    if (year_ss.fail() || month_ss.fail() || day_ss.fail()) throw std::runtime_error("Not a valid date " C "=> " RD + Date);	//	Check if the conversion fails
    if (year < 1900 || year > 2900) throw std::runtime_error("Not a valid date " C "=> " RD + Date);
    if (month < 1 || month > 12) throw std::runtime_error("Not a valid date " C "=> " RD + Date);
    if (day < 1 || day > daysInMonth(year, month)) throw std::runtime_error("Not a valid date " C "=> " RD + Date);
}

//	********* VALIDATE NUMBER *********

bool isAllSpace(const std::string & valueStr) {                                                             //  Check if valueStr only contains spaces
    for (size_t i = 0; i < valueStr.length(); ++i) if (!isspace(valueStr[i])) return (false);               //  If something is not isspace() return False
    return (true);                                                                                          //  else return True
}

static std::string validateNumber(std::string valueStr) {																//	Validate a number as string
    std::size_t k = 0; std::size_t j = valueStr.length();
    while (k < j && std::isspace(valueStr[k])) ++k;																		//	Remove leading and trailing spaces
    while (j > k && std::isspace(valueStr[j - 1])) --j;
    valueStr = valueStr.substr(k, j - k);

    if (valueStr.empty()) throw std::runtime_error("There is no number.");												//	Empty strings are not allowed
    
    int DecimalPoint = 0;
    for (size_t i = 0; i < valueStr.length(); ++i) {
        if (i == 0 && (valueStr[i] == '+' || valueStr[i] == '-')) i++;														//	Only one '+' or '-' is allowed at the beginning of the number
        if (valueStr[i] == '.')																								//	Only one decimal point is allowed
            if (DecimalPoint) throw std::runtime_error("Not a valid number" C " => " RD + valueStr); else DecimalPoint = 1;	//	Check if there is already a decimal point
        else if (i == valueStr.length() - 1 && valueStr[i] == 'f') return (valueStr);										//	Only 'f' is allowed as the last character for floats
        else if (!std::isdigit(valueStr[i])) throw std::runtime_error("Not a valid number" C " => " RD + valueStr);			//	Only digits are allowed
    } return (valueStr);
}

//	********* NUMBER TO STRING *********

std::string valueToString(double Value) {                                                                               // Convert a number to a string
    std::ostringstream oss; oss << std::fixed << std::setprecision(9) << Value; std::string Result = oss.str();         // Convert to string with sufficient precision

    size_t decimalPos = Result.find('.');
    if (decimalPos != std::string::npos) {
        size_t End = Result.find_last_not_of('0');                                                                      // Remove trailing zeros after the decimal point
        if (End != std::string::npos && End > decimalPos) Result.erase(End + 1); else Result.erase(decimalPos);         // Remove decimal point if there are only zeros after it
    } return (Result);
}

//	********* READ DATA.CSV *********

static void readData(std::map <std::string, double> & Prices, const std::string & Filename) {							//	Load 'data.csv' into a map container
    std::ifstream					File(Filename.c_str());
    std::string						Line, Date, valueStr;																//	Declare variables

    if (!File.is_open()) throw std::runtime_error("Could not open the file " G + Filename);								//	Open 'data.csv' file
    while (std::getline(File, Line)) {																					//	Read 'data.csv' file line by line
        if (Line.empty()) continue;																						//	If it is an empty line, continue the while loop
        std::istringstream iss(Line);
        if (std::getline(iss, Date, ',') && std::getline(iss, valueStr)) {												//	Set Date from the beginning of the line until the delimiter
            try {                                                                                                       //	Set valueStr from the delimiter until the end of the line

                validateDate(Date);																						//	Validate Date

                double value; std::istringstream viss(validateNumber(valueStr)); viss >> value;							//	Convert valueStr to double
                if (viss.fail()) throw std::runtime_error("Not a valid number.");										//	Check if the conversion fails
                if (value < 0.0) throw std::runtime_error("Not a positive number.");                                     //	Check if it is less than 0

                Prices[Date] = value;																					//	Add the element to the map container

            } catch (...) {}																							//	In case of error, do nothing and continue
        }
    }
}

//	********* FIND EXCHANGE RATE *********

static std::string closestDate(const std::map <std::string, double> & Prices, const std::string & Date) {				//	Find the exchange rate with the closest date
    std::map <std::string, double>::const_iterator it = Prices.lower_bound(Date);
    if (it != Prices.end() && it->first == Date) return (Date);															//	If there is an exchange rate for the requested date
    else if (it-- != Prices.begin()) return it->first;																	//	If there is a previous exchange rate before the requested date
    else throw std::runtime_error("No date match found.");																//	There is no exchange rate for the requested date
}

//	********* READ INPUT FILE | FIND EXCHANGE RATE | PRINT INFORMATION *********

void bitcoinExchange(std::string Filename) {
    std::map<std::string, double>	Prices;																				//	We will store 'data.csv' in a map container
    std::string 					Line, Date, valueStr;																//	Declare variables
    bool                            Header, Not_Empty; Header = Not_Empty = false;

    try { readData(Prices, "data.csv"); }																				                //	Load 'data.csv'
    catch (const std::exception & e) { std::cerr << RD " Error: " Y << e.what() << "." NC << std::endl; return ; }

    if (Prices.empty()) { std::cerr << RD " Error: " Y " The Bitcoin Price Database is empty." NC << std::endl; return ; }              //	If map container is empty, display an error message  

    std::ifstream File(Filename.c_str());																				                //	Open the file specified by the user
    if (!File.is_open()) { std::cerr << RD " Error: " Y "Could not open the file " G << Filename << Y "." NC << std::endl; return ; }

    while (std::getline(File, Line)) {																					//	Read the file specified by the user line by line
        if (Line.empty() || isAllSpace(Line)) continue;																	//	If it is an empty line, continue the while loop
        std::istringstream iss(Line);
        if (std::getline(iss, Date, '|') && std::getline(iss, valueStr)) {												//	Set the Date from the beginning of the line until the delimiter
            try {																										//	Set valueStr from the delimiter until the end of the line
                
                validateDate(Date);																						//	Validate Date
                if (!Not_Empty) Not_Empty = true;
                double value; std::istringstream viss(validateNumber(valueStr)); viss >> value;							//	Convert valueStr to double
                if (viss.fail()) throw std::runtime_error("Not a valid number" C " => " RD + valueStr);					//	Check if the conversion fails
                                
                if (value < 0.0) throw std::runtime_error("Not a positive number.");									//	Check if it is less than 0
                if (value > 1000.0) throw std::runtime_error("Too large a number.");									//	Check if it is greater than 1000

                std::string Result = valueToString(value * Prices[closestDate(Prices, Date)]);                          //	Find the corresponding date and apply the conversion

                std::cout << G " " << Date << C " => " B << valueToString(value) << C " = " Y << Result << NC << std::endl;     //	Print the information           
            } catch (const std::exception & e) {                                                                                //	Print any errors that occur
                    if (!Header) Header = true;
                    else { std::cerr << RD " Error: " Y << e.what() << NC << std::endl; Not_Empty = true; }
            }
        } else {
            if (!Date.empty())
                std::cerr << RD " Error: " Y "Bad input " C "=> " RD << Line << NC << std::endl;						//	If there is no delimiter, display an error message
            else
                std::cerr << RD " Error: " Y "There is no number." << NC << std::endl;                                  //	If there is no number, display an error message
            Not_Empty = true;
        }
    }
    if (!Not_Empty) std::cerr << RD " Error: " Y "Input File is empty." << NC << std::endl;                             //	If input file is empty, display an error message
    File.close();																										//	Close the file specified by the user (not needed really)
}
