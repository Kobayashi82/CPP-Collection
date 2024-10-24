/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 21:10:52 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
	std::cout << std::endl << " ======================================" << std::endl << std::endl
			  << BR " The " Y "stack" G " container" BR " is useful but lacks one key feature, it's not " C "iterable" BR "," << std::endl
			  << " meaning you can't easily go through its elements one by one like you can with other " G "containers" BR"." << std::endl << std::endl
			  << " To solve this, we create a " B "class" BR " based on " Y "stack" BR " but adds the ability to " G "iterate" BR << std::endl
			  << " through its elements." << std::endl << std::endl
			  << " This new " B "class" BR " is a more flexible version of the traditional " Y "stack" BR "." << std::endl
			  << " In the following tests, a " Y "MutantStack" BR " and a " Y "list" BR " are created, and elements are " C "added" BR ", " C "removed" BR "," << std::endl
              << " their " C "size" BR " is checked, and they are " C "iterated" BR " through." << std::endl << std::endl
              << " The two tests should be identical, as they have the same characteristics." << std::endl << std::endl
              << " If you're wondering why use a " Y "stack" BR " when a " Y "list" BR " offers the same features, it's because of this:" << std::endl << std::endl
			  << Y " Clarity:         " BR "Explicitly represents a " Y "stack" BR ". It's a " G "LIFO" BR " (Last In, First Out)." << std::endl
			  << Y " Restrictions:    " BR "Restricted interface (" C "push" BR ", " C "pop" BR ", " C "top" BR ", " C "size" BR ", and " C "empty" BR "), preventing misuse." << std::endl
			  << Y " Adaptability:    " BR "Is an adapter " G "container" BR ", it can be implemented on top of other " G "container" BR "." << std::endl << std::endl
			  << G " Thank you for evaluating me." NC << std::endl << std::endl;
	{
		{
			std::cout << " ======================================" << std::endl
					<< G "              STACK TESTS             " NC << std::endl 
					<<   " ======================================" << std::endl << std::endl;

			MutantStack <int> mstack;

			mstack.push(5);
			mstack.push(17);
			std::cout << B " Added (" Y "5" B ", " Y "17" B ")" NC << std::endl;
			if (!mstack.empty()) std::cout << C " The current item is\t\t" Y << mstack.top() << NC << std::endl << std::endl;

			if (!mstack.empty()) { mstack.pop(); std::cout  << C " Current item " RD "removed\t" NC << std::endl << std::endl; }

			std::cout << C " The number of items is \t" Y  << mstack.size() << NC << std::endl;

			mstack.push(3);
			mstack.push(5);
			mstack.push(737);
			mstack.push(0);
			std::cout << std::endl << B " Added (" Y "3" B ", " Y "5" B ", " Y "737" B ", " Y "0" B ")" NC << std::endl;
			
			MutantStack <int>::iterator it = mstack.begin();
			MutantStack <int>::iterator ite = mstack.end();
			++it; --it; // Really?

			std::cout << C " The " G "stack" C " looks like this:\t" Y << *it << NC << std::endl;
			while (!mstack.empty() && ++it != ite) std::cout << Y "\t\t\t\t" << *it << NC << std::endl;
			
			if (!mstack.empty()) std::cout << std::endl << C " The current item is\t\t" Y << mstack.top() << NC << std::endl;
			std::cout << std::endl << C " The number of items is \t" Y  << mstack.size() << NC << std::endl;

			std::stack <int> s(mstack);
			
			std::cout << std::endl << std::endl;
		} {
			std::cout << " ======================================" << std::endl
					<< G "               LIST TESTS              " NC << std::endl 
					<<   " ======================================" << std::endl << std::endl;

			std::list <int> lst;

			lst.push_back(5);
			lst.push_back(17);
			std::cout << B " Added (" Y "5" B ", " Y "17" B ")" NC << std::endl;
			if (!lst.empty()) std::cout << C " The current item is\t\t" Y << lst.back() << NC << std::endl << std::endl;

			if (!lst.empty()) { lst.pop_back(); std::cout  << C " Current item " RD "removed\t" NC << std::endl << std::endl; }

			std::cout << C " The number of items is \t" Y  << lst.size() << NC << std::endl;

			lst.push_back(3);
			lst.push_back(5);
			lst.push_back(737);
			lst.push_back(0);
			std::cout << std::endl << B " Added (" Y "3" B ", " Y "5" B ", " Y "737" B ", " Y "0" B ")" NC << std::endl;

			std::list <int>::iterator lst_it = lst.begin();
			std::list <int>::iterator lst_ite = lst.end();
			++lst_it; --lst_it;
			
			std::cout << C " The " G "list" C " looks like this:\t" Y << *lst_it << NC << std::endl;
			while (++lst_it != lst_ite) std::cout << Y "\t\t\t\t" << *lst_it << NC << std::endl;

			if (!lst.empty()) std::cout << std::endl << C " The current item is\t\t" Y << lst.back() << NC << std::endl;
			std::cout << std::endl << C " The number of items is \t" Y  << lst.size() << NC << std::endl;
			
			std::list <int> l(lst);

			std::cout << std::endl;
		}
	}
	std::cout << " =======================================" << std::endl << std::endl;
}
