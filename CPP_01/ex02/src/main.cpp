/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:05:00 by vzurera-          #+#    #+#             */
/*   Updated: 2024/02/21 19:42:31 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

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

void modify(std::string& ref) {
    ref += ", HELP ME SURVIVE THE ZOMBIE APOCALYPSE!";
}

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << std::endl << " " Y UN "stringPTR" NC G " is a pointer, which stores the memory address of the variable it points to." << std::endl
			  << "           In this case, it's storing the memory address of " Y UN "str" NC << std::endl << std::endl;
    std::cout << " " Y UN "stringREF" NC G " is a reference, which is a type of alias for another variable." << std::endl
			  << "           It doesn't store a memory address itself, but rather provides another name for an existing variable." << std::endl
			  << "           Here it is a reference to " Y UN "str" NC G ", so they share the same memory address." << std::endl << std::endl;
    std::cout << RD "	Memory addresses" << std::endl << std::endl;
    std::cout << C "	      The memory address of " UN "str:" NC "	" Y << &str << NC << std::endl;
    std::cout << C "	The memory address of " UN "stringPTR:" NC "	" Y << stringPTR << NC << std::endl;
    std::cout << C "	The memory address of " UN "stringREF:" NC "	" Y << &stringREF << NC << std::endl << std::endl;

    std::cout << RD "	Values before modification" << std::endl << std::endl;
    std::cout << C "	                 The value of " RD UN "str:" NC "	" Y << str << NC << std::endl;
    std::cout << C "	The value pointed to by " RD UN "stringPTR:" NC "	" Y << *stringPTR << NC << std::endl;
    std::cout << C "	The value pointed to by " RD UN "stringREF:" NC "	" Y << stringREF << NC << std::endl << std::endl;

    modify(str);

    std::cout << RD "	Values after modification:" << std::endl << std::endl;
    std::cout << C "	                 The value of " RD UN "str:" NC "	" Y << str << NC << std::endl;
    std::cout << C "	 The value pointed to by" RD UN "stringPTR:" NC "	" Y << *stringPTR << NC << std::endl;
    std::cout << C "	The value pointed to by " RD UN "stringREF:" NC "	" Y << stringREF << NC << std::endl << std::endl;
    std::cout << G "           When a variable is passed by reference to a function, any changes made to the" << std::endl
			  << "           reference inside the function also affect the original variable." << std::endl
			  << "           This is why the values of " Y UN "str" NC G", " Y UN "*stringPTR" NC G ", and " Y UN "stringREF" NC G " have changed after the" << std::endl
			  << "           call to the function " UN "modify." G NC << std::endl << std::endl;
}