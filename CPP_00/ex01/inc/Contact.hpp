/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:52:18 by vzurera-          #+#    #+#             */
/*   Updated: 2024/05/11 17:04:42 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Contact_HPP
# define Contact_HPP

# include <ctime>
# include <iomanip>
# include <sstream>

class Contact {

private:

int			_Index;
std::string _First_Name;
std::string _Last_Name;
std::string _Nickname;
std::string _Phone_Number;
std::string _Darkest_Secret;
std::time_t	_Creation_Date;

public:

	Contact();
	~Contact();
	
	std::string GetFirstName() const;
	std::string GetLastName() const;
	std::string GetNickname() const;
	std::string GetPhoneNumber() const;
	std::string GetDarkestSecret() const;
	std::time_t GetCreationDate() const;
	std::string GetCreationDateStr() const;
	int 		GetIndex() const;

	void SetFirstName(std::string FName);
	void SetLastName(std::string LName);
	void SetNickname(std::string Nick);
	void SetPhoneNumber(std::string Number);
	void SetDarkestSecret(std::string Secret);
	void SetCreationDate();
	void SetIndex(int New_Index);
};

#endif