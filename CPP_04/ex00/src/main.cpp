/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 19:28:43 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
	std::cout << std::endl << " =======================================" << std::endl << std::endl
	
			  << Y " Polymorphism" BR " allows objects of different classes to be treated as objects of a common class." << std::endl << std::endl
			  << " This is achieved through " G "class inheritance" BR " and the implementation of " Y "virtual" BR " methods, allowing" << std::endl
			  << " the same method to have different implementations in different classes." << std::endl << std::endl

			  << " There are two types of " Y "Polymorphism" BR ":" << std::endl << std::endl
			  
			  << Y " Compile-time Polymorphism:" BR " Achieved through " G "function overloading" BR " and " G "operator overloading" BR "." << std::endl
			  << " Multiple functions can have the same name but with different parameters, allowing the function" << std::endl
			  << " to behave differently based on its arguments." << std::endl << std::endl

			  << Y " Runtime Polymorphism:" BR " Achieved through the use of " Y "virtual" BR " functions and " G "inheritance" BR "." << std::endl
			  << " It allows a call to a member function of a " G "base class" BR " to be resolved at runtime to the" << std::endl
			  << " corresponding member function of a " G "derived class" BR "." << std::endl << std::endl

			  << " For " Y "runtime polymorphism" BR ", the " Y "virtual" BR " keyword is used, ensuring the correct function" << std::endl
			  << " corresponding to the object used is called." << std::endl << std::endl

			  << " For example, if we have an object that is a " G "pointer" BR " of type " Y "Animal" BR " and we assign to it an" << std::endl
			  << " object of type " Y "Dog" BR ", even though it was declared as " Y "Animal" BR ", we can access the methods of " Y "Dog" BR "." << std::endl << std::endl
			  
			  << " This is possible because of " Y "polymorphism" BR ", which allows an object to be treated as an object of" << std::endl
			  << " its " G "base class" BR " (" Y "Animal" BR " in this case), but still retain its " G "derived class" BR " (" Y "Dog" BR ") behaviors." << std::endl << std::endl

			  << " In this exercise, a " G "base class" Y " Animal" BR " is created with the " Y "virtual" BR " keyword in its " Y "makeSound()" BR << std::endl
			  << " and " Y "destructor" BR " methods." << std::endl << std::endl
			  << " Each " G "derived class" BR " (" Y "Dog" BR " and " Y "Cat" BR ") has its own " Y "makeSound()" BR " method that reproduces the corresponding" << std::endl
			  << " animal sound." << std::endl << std::endl

			  << " Thus, if we call the " Y "makeSound()" BR " method, the correct method will be executed based on the object" << std::endl
			  << " from which we call it." << std::endl << std::endl
			  
			  << " Then we have the " Y "WrongAnimal" BR " class, which does not have the " Y "virtual" BR " keyword in its " Y "makeSound()" BR << std::endl
			  << " method (although it does in its destructor)," << std::endl << std::endl
			  
			  << " Which means that when we call a " Y "WrongAnimal" BR " object that has a " G "derived class" BR " of " Y "WrongCat" BR ", only the " Y << std::endl
			  << " makeSound()" BR " method of " Y "WrongAnimal" BR " will be called." NC << std::endl << std::endl;
			  
	{
		//	DEFAULT TESTS

		std::cout << " =======================================" << std::endl
				  << G "      DEFAULT TESTS (see Subject)" NC << std::endl
				  << " =======================================" << std::endl << std::endl
				  << BR " We create an object " Y "Animal" BR ", " Y "Dog" BR " and " Y "Cat" NC << std::endl << std::endl;

		const Animal* meta = new Animal();				std::cout << std::endl;
		const Animal* j = new Dog();					std::cout << std::endl;
		const Animal* i = new Cat();					std::cout << std::endl;
		
		std::cout << " ——————————————————————————————————————" Y << std::endl << std::endl;
		
		std::cout << BR " We show the object " Y "type" BR " using " Y "getType()" BR " method" NC << std::endl << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << std::endl << BR " We show the object " Y "sound" BR " using " Y "makeSound()" BR " method" NC << std::endl << std::endl;
		i->makeSound(); j->makeSound(); meta->makeSound();

		std::cout << std::endl << NC " ——————————————————————————————————————" << std::endl << std::endl;
		
		std::cout << BR " Finally, we destroy all the objects" NC << std::endl << std::endl;
		delete meta;									std::cout << std::endl;
		delete j;										std::cout << std::endl;
		delete i;										std::cout << std::endl << std::endl ;
		
		//	MY OWN TEST

		std::cout << " =======================================" << std::endl
				  << G "              MY OWN TESTS" NC << std::endl
				  << " =======================================" << std::endl << std::endl
				  << BR " We create an object " Y "Dog" BR ", " Y "Cat" BR ", " Y "WrongCat" BR " and " Y "WrongAnimal" BR " but this last one is a " << std::endl
				  << " pointer to a " Y "WrongCat" BR " class" NC << std::endl << std::endl;
				  
		Dog dog;										std::cout << std::endl;
		Cat cat;										std::cout << std::endl;
		WrongCat wrong_cat;								std::cout << std::endl;
		WrongAnimal* wrong_animal = new WrongCat();		std::cout << std::endl;

		std::cout << std::endl << " ——————————————————————————————————————" << std::endl << std::endl;
		
		std::cout << C "The " Y << dog.getType() 			<< C "\t\tsounds like...\t " Y;		dog.makeSound();
		std::cout << C "The " Y << cat.getType() 			<< C "\t\tsounds like...\t " Y;		cat.makeSound();
		std::cout << C "The " Y << wrong_cat.getType() 		<< C "\tsounds like...\t " Y; 		wrong_cat.makeSound();
		std::cout << C "The " Y << wrong_animal->getType() 	<< C "\tsounds like...\t " Y; 		wrong_animal->makeSound();

		std::cout << std::endl << BR " The first " Y "WrongCat" BR " is a " Y "WrongCat" BR " class therefore its own " Y "makeSound()" BR " method prevails." << std::endl << std::endl
				  << " The second " Y "WrongCat" BR " is a " G "pointer" BR " of type " Y "WrongAnimal" BR " and has been assigned with " B "new" G " WrongCat" B "()" BR "." << std::endl << std::endl
				  << " Since the " Y "WrongAnimal" BR " class does not have the " Y "virtual" BR " keyword in its " Y "makeSound()" BR " function," << std::endl
				  << " the method from the " G "base class" Y " WrongAnimal" BR " is called." NC << std::endl;

		std::cout << std::endl << std::endl << " ——————————————————————————————————————" << std::endl << std::endl;
		
		std::cout << BR " Finally, we destroy all the objects" NC << std::endl << std::endl;
		delete wrong_animal;							std::cout << std::endl;
	}
	std::cout << std::endl << " =======================================" << std::endl << std::endl;
}
