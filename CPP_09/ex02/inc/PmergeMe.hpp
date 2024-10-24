/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:00:11 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/19 19:30:15 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Colors.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>

#define NFILE 30
void sortVector(int argc, char **argv);
void sortDeque(int argc, char **argv);
void sortList(int argc, char **argv);

int getVectorComparisons();
int getDequeComparisons();
int getListComparisons();

const std::vector<int> getVector();
const std::deque<int> getDeque();
const std::list<int> getList();

const std::vector<int> getVectorMainChain();
const std::deque<int> getDequeMainChain();
const std::list<int> getListMainChain();

bool isAllSpace(const std::string & valueStr) ;
std::string validateNumber(std::string valueStr);

//	********* LOAD CONTAINER *********

template <typename Container> void loadContainer(int argc, char **argv, Container & container) {
    int Number; std::string Expression, valueStr;
    for (int i = 1; i < argc; ++i) { Expression += std::string(argv[i]) + " "; }                            //	Join args into a single string separate by space
    std::istringstream exprStream(Expression);
    while (std::getline(exprStream, valueStr, ' ')) {
        if (valueStr.empty() || isAllSpace(valueStr)) continue;                                             // Ignore empty strings
        std::istringstream iss(validateNumber(valueStr)); iss >> Number;							        // Convert from string to integer
        if (iss.fail()) throw std::runtime_error("Invalid input");							                // If convertion fails or number is negative throw an error
        container.push_back(Number);																	    // Add the number to the container
    }
    if (container.size() == 0) throw std::runtime_error("Invalid input");							        // If container is empty throw an error
}

//	********* PRINT CONTAINER *********

template <typename Container> void printContainer(const Container & container, const std::string & Action) {
	std::string Color = G, Color_Name = Y, Name = "";
	if (Action == "Before") { std::cout << RD " Before:   " NC; Name = "unsorted.txt"; Color = RD; Color_Name = RD; }
	else if (Action == "Vector") { std::cout << B " Vector:   " NC; Name = "vector_sorted.txt"; }
	else if (Action == "Deque") { std::cout << B " Deque:    " NC; Name = "deque_sorted.txt"; }
	else if (Action == "List") { std::cout << B " List:     " NC; Name = "list_sorted.txt"; }
	if (Name == "") return ;
    if (container.size() > NFILE) {
        std::ofstream file(Name.c_str());
		if (Name == "unsorted.txt") { Name += "\t"; }
        if (!file.is_open()) { std::cout << C "Saved to file " << Color_Name << Name << RD "\t failed" NC << std::endl << std::endl; return ; }
		std::cout << C "Saved to file " << Color_Name << Name << G "\t succesfully" NC << std::endl << std::endl;;
        for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) { file << *it;
            typename Container::const_iterator next = it; ++next; if (next != container.end()) file << " ";
        } file.close();
    } else {
        for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) { std::cout << Color << *it;
            typename Container::const_iterator next = it; ++next; if (next != container.end()) std::cout << " ";
        } std::cout << std::endl << std::endl;
    }
}
