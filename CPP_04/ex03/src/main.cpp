/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 19:57:22 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main() {
	std::cout << std::endl << " ======================================" << std::endl << std::endl
			  << BR " This exercise is a bit more complicated. The goal is to create " Y "characters" BR " with" << std::endl
              << " an " C "inventory" BR " of 4 slots to store " G "materials" BR " (or " G "weapons" BR ")." << std::endl << std::endl
              << " These " G "materials" BR " must be learned (" C "added" BR " to a class that stores them) and then we can" << std::endl
              << C " clone" BR " them to " G "equip" BR " our " Y "characters" BR "." << std::endl << std::endl
              << Y " Characters" BR " can " G "equip" BR " these " G "materials" BR ", " G "unequip" BR " them, or " G "use" BR " them on another " Y "character" BR "." << std::endl << std::endl
              << " We will have to use " B "class hierarchy" BR ", " G "abstract classes" BR ", " Y "interfaces" BR ", and in this case" << std::endl
              << " a " G "static class" BR ", which is a type of " B "class" BR " that does not need to be " G "instantiated" BR " and its" << std::endl
              << " methods can be called directly." << std::endl << std::endl
              << " This " G "static class" BR ", which is not requested by the exercise, I use to store the " B "pointers" BR " of" << std::endl
              << " the " G "materials" BR " that are on the " B "floor" BR "." << std::endl << std::endl
              << " A material can be on the " B "floor" BR " because a " Y "character's" C " inventory" BR " is full when trying to" << std::endl
              << G " equip" BR " a " G "material" BR " or because a " Y "character" G " unequips" BR " it." << std::endl << std::endl
              << " A requirement of the exercise is that " G "materials" BR " should not be released or freed when " G "unequipping" BR << std::endl
              << " them, simulating that they are left on a virtual " B "floor" BR "." << std::endl << std::endl
              << " For this reason, by having the " B "pointers" BR " stored in a " G "static class" BR ", I can release them at the" << std::endl
              << " end of the program with its " Y "clear()" BR " method." << std::endl << std::endl
              << " Speaking of " Y "interfaces" BR ", in " B "C++" BR " an " Y "interface" BR " is actually an " G "abstract class" BR " in which all its" << std::endl
              << " members are " Y "purely virtual" BR " and it does not store any " G "data" BR "." << std::endl << std::endl
              << " It serves as a contract that specifies what actions the " G "derived classes" BR " must be able to perform," << std::endl
              << " without providing any " G "implementation" BR "." << std::endl << std::endl
              << " Having said all this, it only remains to remind the " G "evaluators" BR " that they can use" << std::endl
			  << Y " valgrind --leak-check=full ./Materia" BR " to check for leaks in this exercise and say:" << std::endl << std::endl
              << G " Thank you for evaluating me." NC << std::endl << std::endl;
	{

		std::cout <<   " ======================================" << std::endl
				  << G "              DEFAULT TESTS            " NC << std::endl
				  <<   " ======================================" << std::endl << std::endl;
		{
			IMateriaSource* src = new MateriaSource();
			src->learnMateria(new Ice());
			src->learnMateria(new Cure());

			ICharacter* me = new Character("me");

			AMateria* tmp;
			tmp = src->createMateria("ice");
			me->equip(tmp);
			tmp = src->createMateria("cure");
			me->equip(tmp);

			ICharacter* bob = new Character("bob");

			me->use(0, *bob);
			me->use(1, *bob);

			delete bob;
			delete me;
			delete src;

			Floor::clear();

			std::cout << std::endl << std::endl;
		}
	
		std::cout <<   " ======================================" << std::endl
				  << G "                OWN TESTS              " NC << std::endl
				  <<   " ======================================" << std::endl << std::endl;
		{
			//	Create materia source and learn new materias
			IMateriaSource * src = new MateriaSource();

			std::cout << BR " Learn materials (" B "Ice" BR " and " G "Cure" BR ") and create characters (" Y "Alice" BR ", " Y "Bob" BR " and " Y "Charlie" BR ")" NC << std::endl << std::endl;
			src->learnMateria(new Ice());
			src->learnMateria(new Ice());
			src->learnMateria(new Cure());
			src->learnMateria(new Cure());
			src->learnMateria(new Cure());						//	This one is not learned
			src->learnMateria(NULL);							//	This one is ignored

			//	Create characters
			ICharacter* alice = new Character("Alice");
			ICharacter* bob = new Character("Bob");
			ICharacter* charlie = new Character("Charlie");

			//	Alice learns materias
			std::cout << Y " Alice" BR " get some equipment" NC << std::endl << std::endl;
			alice->equip(src->createMateria("ice"));
			alice->equip(src->createMateria("cure"));

			//	Bob learns materias
			std::cout << std::endl << Y " Bob" BR " get some equipment" NC << std::endl << std::endl;
			bob->equip(src->createMateria("ice"));
			bob->equip(src->createMateria("cure"));
			bob->equip(src->createMateria("ice"));
			bob->equip(src->createMateria("cure"));
			bob->equip(src->createMateria("ice"));				//	This drops to the floor
			bob->equip(src->createMateria("cure"));				//	This drops to the floor
			bob->equip(NULL);									//	This one is ignored

			std::cout << std::endl << Y " Charlie" BR " get some equipment" NC << std::endl << std::endl;
			std::cout << Y "Charlie" C " is unarmed" NC << std::endl << std::endl;

			std::cout << std::endl << " ——————————————————————————————————————" Y << std::endl << std::endl;

			//	Use of materias
			std::cout << BR " Combat starts (" G "Round 1" BR ")" NC << std::endl << std::endl;
			bob->use(0, *charlie);		std::cout << std::endl;	//	Bob uses Ice on Charlie
			alice->use(1, *charlie);	std::cout << std::endl;	//	Alice uses Cure on Charlie

			std::cout << BR " Combat starts (" G "Round 2" BR ")" NC << std::endl << std::endl;
			alice->use(0, *bob);		std::cout << std::endl;	//	Alice uses Ice on Bob
			bob->use(0, *alice);		std::cout << std::endl;	//	Bob uses Ice on Alice
			bob->use(1, *bob);		std::cout << std::endl;		//	Bob uses Cure on Bob

			std::cout << BR  "Combat starts (" G "Round 3" BR ")" NC << std::endl << std::endl;
			alice->use(1, *alice);	std::cout << std::endl;		//	Alice uses Cure on Alice
			charlie->use(0, *charlie);	std::cout << std::endl;	//	Charlie uses nothing on himself WTF!!
			bob->use(999, *charlie);	std::cout << std::endl;	//	Bob uses nothing on Charlie

			std::cout << " ——————————————————————————————————————" Y << std::endl << std::endl;
			
			//	Unequip and drop materia to the ground
			std::cout<< Y " Alice" BR " unequiped all his materials" NC << std::endl << std::endl;
			alice->unequip(0);
			alice->unequip(1);
			alice->unequip(2);									//	No material here
			alice->unequip(3);									//	No material here
			alice->unequip(4);									//	This one is out of bound

			std::cout << std::endl << Y " Bob" BR " wants to keep his materials" NC << std::endl << std::endl;

			//	Use of materias after unequipping (should fail)
			std::cout << Y " Alice" BR " and " Y "Charlie" BR " try to attack " Y "Bob" BR " without materials" NC << std::endl << std::endl;
			alice->use(0, *bob); 								// Attempt to use an unequipped materia
			charlie->use(1, *bob); 								// Attempt to use an unequipped materia

			std::cout << std::endl << std::endl << " ——————————————————————————————————————" Y << std::endl << std::endl;

			//	Cleaning
			std::cout << BR " Release " Y "Bob's" BR " and " B "floor's" BR " materials" NC << std::endl << std::endl;

			delete alice;
			delete bob;
			delete charlie;
			delete src;

			//	Clean up materials on the floor
			Floor::clear();
		}
	}
	std::cout << " =======================================" << std::endl << std::endl;

}
