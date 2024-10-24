/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:14:22 by vzurera-          #+#    #+#             */
/*   Updated: 2024/06/25 09:27:07 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer(std::string Path) : _Input_File(Path.c_str()), _Output_File(_Input_File + ".replace") {
}

Replacer::~Replacer() {
}

int Replacer::replace(std::string s1, std::string s2) {
	std::ifstream Open(_Input_File.c_str());
	if (!Open.is_open()) throw std::runtime_error("Error opening input file");
    std::ofstream Save(_Output_File.c_str());
    if (!Save.is_open()) throw std::runtime_error("Error opening output file");	
	try {
		std::string Content;
		if (!std::getline(Open, Content, '\0')) return (-1);
		Open.close();
		int nb_Replaces = 0;
		size_t start_pos = 0;
		while((start_pos = Content.find(s1, start_pos)) != std::string::npos) {
			Content.erase(start_pos, s1.length());
			Content.insert(start_pos, s2);
			start_pos += s2.length();
			nb_Replaces += 1;
		}
		Save << Content; Save.close();
		return (nb_Replaces);
	} catch(...) {
		return (-1);
	}
}