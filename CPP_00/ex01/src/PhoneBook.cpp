/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:52:18 by vzurera-          #+#    #+#             */
/*   Updated: 2024/05/11 17:29:47 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
}

PhoneBook::~PhoneBook() {
}

bool PhoneBook::_ValidateData(std::string Data) {
	bool	AllSpace = true;

	for (std::string::size_type i = 0; i < Data.size(); ++i) {
		char c = Data[i];
		if (c != ' ') { AllSpace = false; break; }
	}
	if (Data.empty() || AllSpace) {
		std::cout  << std::endl << RD "	The entry can't be empty" NC << std::endl;
		return (false);
	}
	return (true);
}

int PhoneBook::Add() {
	Contact	New_Contact;
	std::string command;

	_OldestContact = 0;
	_OldestDate = std::time(0);
	for (int i = 0; i < MAX_CONTACTS; i++) {
		if (_Contacts[i].GetCreationDate() < _OldestDate)
		{
			_OldestDate = _Contacts[i].GetCreationDate();
			_OldestContact = i;
		}
	}
	std::cout << std::endl << G "  	Add new contact in index " Y << _OldestContact;
	if (!_Contacts[_OldestContact].GetFirstName().empty())
		std::cout << RD "  	The contact " G UN << _Contacts[_OldestContact].GetFirstName() << NC RD " will be overwrited!";
	std::cout << std::endl << std::endl;
	//	FIRST NAME
	std::cout << Y "               First Name:	" NC;
	if (!std::getline(std::cin, command)) std::cout << std::endl;
	if (_ValidateData(command) == false) return (1);
	New_Contact.SetFirstName(command);
	//	LAST NAME
	std::cout << Y "                Last Name:	" NC;
	if (!std::getline(std::cin, command)) std::cout << std::endl;
	if (_ValidateData(command) == false) return (1);
	New_Contact.SetLastName(command);
	//	NICKNAME
	std::cout << Y "                 Nickname:	" NC;
	if (!std::getline(std::cin, command)) std::cout << std::endl;
	if (_ValidateData(command) == false) return (1);
	New_Contact.SetNickname(command);
	//	PHONE NUMBER
	std::cout << Y "             Phone Number:	" NC;
	if (!std::getline(std::cin, command)) std::cout << std::endl;
	if (_ValidateData(command) == false) return (1);
	New_Contact.SetPhoneNumber(command);
	//	DARKEST SECRET
	std::cout << Y "           Darkest Secret:	" NC;
	if (!std::getline(std::cin, command)) std::cout << std::endl;
	if (_ValidateData(command) == false) return (1);
	New_Contact.SetDarkestSecret(command);
	New_Contact.SetCreationDate();
	New_Contact.SetIndex(_OldestContact);
	_Contacts[_OldestContact] = New_Contact;
	std::cout << std::endl << G "  	New contact created succesfully" NC << std::endl;
	return (0);
}

void PhoneBook::Search() {
	std::string command;
    int 		index = -1;
	int			max_index = -1;

	std::cout << std::endl << G "  		List of contacts" NC << std::endl << std::endl;
 	std::cout << C "|——————————|——————————|——————————|——————————|" << std::endl;
	std::cout << C "|——————————|——————————|——————————|——————————|" << std::endl;
 	std::cout << std::setw(10) << C "|" Y "   Index  " << C "|"
              << std::setw(10) << Y "First Name" << C "|"
              << std::setw(10) << Y " Last Name" << C "|"
              << std::setw(10) << Y " Nickname " C "|" NC << std::endl;
	std::cout << C "|——————————|——————————|——————————|——————————|" << std::endl;
    for (int i = 0; i < MAX_CONTACTS; i++) {
		if (_Contacts[i].GetFirstName().empty() == false)
		{
			max_index = i;
			std::cout << C "|" NC << std::setw(10) << i << C "|" NC
					  << std::setw(10) << _Truncate(_Contacts[i].GetFirstName(), 10) << C "|" NC
				   	  << std::setw(10) << _Truncate(_Contacts[i].GetLastName(), 10) << C "|" NC
					  << std::setw(10) << _Truncate(_Contacts[i].GetNickname(), 10) << C "|" << std::endl;
			std::cout << C "|——————————|——————————|——————————|——————————|" << std::endl;
		}
    }
	if (max_index == -1) return ;
	std::cout << std::endl << std::endl << C "Select an index:		" NC;
    if (std::getline(std::cin, command) && command.find_first_not_of("0123456789") == std::string::npos)
	{
		std::stringstream ss(command);
	    if (!(ss >> index)) index = -1;
	}
    if (index < 0 || index > max_index) {
        std::cout << std::endl << RD "		Invalid index" NC << std::endl;
    } else {
        Show(index);
    }
}

std::string PhoneBook::_Truncate(const std::string& str, size_t width) const {
    if (str.length() > width) {
        return str.substr(0, width - 1) + ".";
    } else {
        return str;
    }
}

void PhoneBook::Show(int index) {
	std::cout << std::endl
			  << Y "	    First Name: 	" C << _Contacts[index].GetFirstName() << std::endl
			  << Y "	     Last Name: 	" C << _Contacts[index].GetLastName() << std::endl
			  << Y "	      Nickname: 	" C << _Contacts[index].GetNickname() << std::endl
			  << Y "	  Phone Number: 	" C << _Contacts[index].GetPhoneNumber() << std::endl
			  << Y "	Darkest Secret: 	" C << _Contacts[index].GetDarkestSecret() << std::endl
			  << Y "	 Creation Date: 	" C << _Contacts[index].GetCreationDateStr() << NC<< std::endl;

}
