/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:47:38 by vzurera-          #+#    #+#             */
/*   Updated: 2024/02/23 00:11:48 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main() {
	Harl Harl;
	
	std::cout << std::endl;
	Harl.complain("WARNING");
	Harl.complain("DEBUG");
	Harl.complain("ERROR");
	Harl.complain("INFO");
	Harl.complain("ERROR");
	Harl.complain("DEBUG");
	Harl.complain("WARNING");
	Harl.complain("INFO");
	std::cout << std::endl;
}