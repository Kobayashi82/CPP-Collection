/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:52:18 by vzurera-          #+#    #+#             */
/*   Updated: 2024/05/11 17:15:07 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
	_Index = 0;
	_First_Name = "";
	_Last_Name = "";
	_Nickname = "";
	_Phone_Number = "";
	_Darkest_Secret = "";
	_Creation_Date = std::time(0);
}

Contact::~Contact() {
}

std::string Contact::GetFirstName() const {
	return (_First_Name);
}
std::string Contact::GetLastName() const {
	return (_Last_Name);
}
std::string Contact::GetNickname() const {
	return (_Nickname);
}
std::string Contact::GetPhoneNumber() const {
	return (_Phone_Number);
}
std::string Contact::GetDarkestSecret() const {
	return (_Darkest_Secret);
}
std::time_t Contact::GetCreationDate() const {
	return (_Creation_Date);
}
std::string Contact::GetCreationDateStr() const {
    char buffer[80];
    std::tm* tm = std::localtime(&_Creation_Date);
    strftime(buffer, sizeof(buffer), "%d/%m/%Y - %H:%M:%S", tm);
    return std::string(buffer);
}
int Contact::GetIndex() const {
	return (_Index);
}

void Contact::SetFirstName(std::string FName) {
	_First_Name = FName;
}
void Contact::SetLastName(std::string LName) {
	_Last_Name = LName;
}
void Contact::SetNickname(std::string Nick) {
	_Nickname = Nick;
}
void Contact::SetPhoneNumber(std::string Number) {
	_Phone_Number = Number;
}
void Contact::SetDarkestSecret(std::string Secret) {
	_Darkest_Secret = Secret;
}
void Contact::SetCreationDate() {
	_Creation_Date = std::time(0);
}
void Contact::SetIndex(int New_Index) {
	_Index = New_Index;
}