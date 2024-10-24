/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:14:19 by vzurera-          #+#    #+#             */
/*   Updated: 2024/02/22 23:56:13 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

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

class Harl {

	public:

		Harl();
		~Harl();

		void complain(std::string Level);

	private:

		void debug();
		void info();
		void warning();
		void error();

};
#endif