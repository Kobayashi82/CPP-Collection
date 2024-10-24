/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 19:43:03 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
	std::cout << std::endl << " ======================================" << std::endl << std::endl

			  << BR " In this exercise, we expand on what we have done in the previous exercise by adding another" << std::endl
			  << " class called " Y "Brain" BR ", which contains an array of 100 " Y "strings" BR " that are used to store" << std::endl
			  << " the ideas that pass through the animal's little head." << std::endl << std::endl
			  << " We must ensure to properly create and destroy the " Y "Brain" BR " object and perform a " G "deep copy" BR "," << std::endl
			  << " which means that a " G "pointer" BR " or " G "reference" BR " will not be assigned, but the values will be copied." << std::endl << std::endl
			  << " This will prevent accessing freed data." NC << std::endl << std::endl;
	{
		//	ANIMAL ARRAY TEST

		std::cout << " ======================================" << std::endl
				  << G "\t   ANIMAL ARRAY TEST" NC
				  << std::endl << " ======================================" << std::endl << std::endl
				  << BR " We create an array of " Y "Animal" BR " where half are " Y "Dogs" BR " and the other half are " Y "Cats" NC << std::endl;
        int Total_Animals = 6;
        Animal* Animals[Total_Animals];

		//	We can use alternate Dogs and Cats or half and half
    //	for (int i = 0; i < Total_Animals; i++) { std::cout << std::endl; if (i % 2) Animals[i] = new Dog(); else Animals[i] = new Cat(); }
		for (int i = 0; i < Total_Animals; i++) { std::cout << std::endl; if (i < Total_Animals / 2) Animals[i] = new Dog(); else Animals[i] = new Cat(); }
		std::cout << std::endl << std::endl << " ——————————————————————————————————————" << std::endl << std::endl;

		std::cout << BR " Now we call the methods " Y "getType()" BR " and " Y "makeSound()" NC << std::endl << std::endl;
		//	The makeSound() method called depends on the type of object
		for (int i = 0; i < Total_Animals; i++) { std::cout << C "The " Y << Animals[i]->getType() << C "       sounds like... " Y; Animals[i]->makeSound(); }
		std::cout << std::endl << std::endl << NC " ——————————————————————————————————————" << std::endl << std::endl;

		std::cout << BR " Finally, we destroy all the objects " Y "Animal" BR " in the array" NC << std::endl;
		//	When we destroy the Animals, the destructor method of the derived class Dog or Cat is called (thanks to polymorphism and the virtual keyword) before the Animal object is destroyed. 
		//	In the destructor of Dog or Cat, the Brain objects are also explicitly destroyed.
        for (int i = 0; i < Total_Animals; i++) { std::cout << std::endl; delete Animals[i]; }

		//	DEEP COPY TEST

		std::cout << std::endl << std::endl << " ======================================" << std::endl
				  << G "\t     DEEP COPY TEST" NC
				  << std::endl << " ======================================" << std::endl << std::endl;

		std::cout << BR " We create a " G "pointer" BR " to an object of type " Y "Dog" NC << std::endl << std::endl;
		Dog* a = new Dog(); 	std::cout << std::endl;
		std::cout << BR " We create a " G "pointer" BR " to an object of type " Y "Cat" NC << std::endl << std::endl;
		Cat* b = new Cat(); 	std::cout << std::endl;
		std::cout << BR " We create another " G "pointer" BR " to an object of type " Y "Dog" BR " (this is " Y "Other Dog" BR ")" NC << std::endl << std::endl;
		Dog* c = new Dog(); 	std::cout << std::endl;
		std::cout << BR " We assign a copy of the first " Y "Dog" BR " to the " Y "Other Dog" NC << std::endl << std::endl;
		*c = *a;				std::cout << std::endl;

		std::cout << std::endl << NC " ——————————————————————————————————————" << std::endl << std::endl;
		std::cout << BR " We display the animals' ideas using the method " Y "getIdea()" NC << std::endl << std::endl;

		a->setIdea(0, "'I want to play'");
		b->setIdea(0, "'I want to conquer the world'");
		c->setIdea(0, "'I want to eat'");
		c->setIdea(1, "'I want to sleep'");

		std::cout << C "The " Y 					<< a->getType() << Y "'s" C "\t  first idea is\t\t" Y 		<< a->getIdea(0) << std::endl;
		std::cout << C "The " Y 					<< b->getType() << Y "'s" C "\t  first idea is\t\t" Y 		<< b->getIdea(0) << std::endl;
		std::cout << C "The " Y "Other " 				<< c->getType() << Y "'s" C "\t  first idea is\t\t" Y 		<< c->getIdea(0) << std::endl;
		std::cout << C "The " Y "Other " 				<< c->getType() << Y "'s" C "\t  second idea is\t" Y 		<< c->getIdea(0) << std::endl;
		b->setIdea(0, "'I want to kill humans'");
		std::cout << C "The " Y 					<< b->getType() << Y "'s" C "\t  first idea now is\t" Y 	<< b->getIdea(0) << std::endl;
		
		std::cout << std::endl << std::endl << NC " ——————————————————————————————————————" << std::endl << std::endl;
		std::cout << BR " Finally, we destroy all the objects" NC << std::endl << std::endl;
		delete a; 				std::cout << std::endl;
		delete b; 				std::cout << std::endl;
		delete c; 				std::cout << std::endl;
	}
	std::cout << " =======================================" << std::endl << std::endl;

	//	Uncoment to test
	// {
	// 	Dog basic;				std::cout << std::endl;
	// 	{
	// 		Dog tmp = basic;	std::cout << std::endl;
	// 	}
	// 							std::cout << std::endl;
	// }
	// std::cout << std::endl << " =======================================" << std::endl << std::endl;
}
