/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:52:18 by vzurera-          #+#    #+#             */
/*   Updated: 2024/05/11 17:07:34 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBook_HPP
# define PhoneBook_HPP

# include "Contact.hpp"
# include <iostream>
# include <ctime>

# define NC   	"\033[0m"		// Default
# define RD		"\033[1;31m"	// Bold Red
# define G     	"\033[1;32m"	// Bold Gree
# define Y     	"\033[1;33m"	// Bold Yellow
# define B     	"\033[1;34m"	// Bold Blue
# define M     	"\033[1;35m"	// Bold Magenta
# define C     	"\033[1;36m"	// Bold Cyan
# define W     	"\033[1;37m"	// Bold White

# define UN 	"\033[4m"		// Underline
# define IT 	"\033[3m"		// Italic

# ifndef MAX_CONTACTS
#  define MAX_CONTACTS 8
# endif

class PhoneBook {

private:

	Contact		_Contacts[MAX_CONTACTS];
	int			_OldestContact;
	std::time_t	_OldestDate;

	bool _ValidateData(std::string Data);
	std::string _Truncate(const std::string& str, size_t width) const;

public:

	PhoneBook();
	~PhoneBook();
	
	int Add();
	void Search();
	void Show(int index);
};

#endif