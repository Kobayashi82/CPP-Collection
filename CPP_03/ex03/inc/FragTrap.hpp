/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:22:07 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 19:07:22 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

	public :

		//	Constructors
		
		FragTrap(std::string Name);
		FragTrap(const FragTrap &src);
		virtual ~FragTrap();

		//	Functions

		void attack(const std::string & target);
		void highFivesGuys(void);

		// Overloads
		
		FragTrap& operator=(const FragTrap& rhs);
	
};

#endif
