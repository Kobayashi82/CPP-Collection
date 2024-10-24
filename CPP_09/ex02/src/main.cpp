/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 15:30:38 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//	./PmergeMe $(shuf -i 1-3000 -n 3000 | tr "\n" " ")
//	Añadir informacion y better parsing
//	diff3 vector_sorted.txt deque_sorted.txt list_sorted.txt

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout  << std::endl << RD "       Incorrect number of arguments" << std::endl << std::endl;
		std::cout << C "\tUsage: " Y "./PmergeMe [" G "Numbers" Y "]" NC << std::endl << std::endl;
		return (0);
    }
	try {

		std::clock_t Start = std::clock(); sortVector(argc, argv);											//	Start timer and sort Vector
		double VectorTime = (1000.0 * (std::clock() - Start)) / CLOCKS_PER_SEC;  							//	Calculate the elapsed time in milliseconds. CLOCKS_PER_SEC specifies the number of clock ticks per second

		if (getVector().size() > 10000) {
			std::cout << std::endl << " ======================================" << std::endl
					  << std::endl << C " Please wait, this may take a while..." NC << std::endl
					  << std::endl << " ======================================" << std::endl << std::endl;
		}

		Start = std::clock(); sortDeque(argc, argv);  														//	Start timer and sort Deque
		double DequeTime = (1000.0 * (std::clock() - Start)) / CLOCKS_PER_SEC; 								//	Calculate the elapsed time in milliseconds. CLOCKS_PER_SEC specifies the number of clock ticks per second

		Start = std::clock(); sortList(argc, argv);  														//	Start timer and sort List
		double ListTime = (1000.0 * (std::clock() - Start)) / CLOCKS_PER_SEC; 								//	Calculate the elapsed time in milliseconds. CLOCKS_PER_SEC specifies the number of clock ticks per second

		if (getVector().size() <= 10000)
			std::cout << std::endl << " ======================================" << std::endl << std::endl;
        std::cout << BR " This exercise demonstrates the implementation of the " Y "Ford-Johnson" BR " merge-insert sort algorithm. " << std::endl << std::endl
				  << " The " Y "Ford-Johnson" BR " algorithm is an efficient sorting technique that does not aim to be the " G "fastest" BR "," << std::endl
				  << " but rather to perform the " G "fewest" BR " possible " G "comparisons" BR "." << std::endl << std::endl
				  << " An example could be if for each " G "comparison" BR " we had to access an " C "API" BR ", and therefore the access" << std::endl
				  << " time is very " G "slow" BR "." << std::endl << std::endl
				  << " In these cases, reducing the number of " G "comparisons" BR " can end up being " G "faster" BR " than other algorithms." << std::endl << std::endl

        		  << " The " C "program" BR " takes a sequence of " B "positive" BR " integers as input, " G "sorts" BR " them using the " Y "Ford-Johnson" BR << std::endl
				  << " algorithm, and measures the " G "time" BR " and number of " G "comparisons" BR " taken to " G "sort" BR " the sequence using" << std::endl
				  << " three different " B "containers" BR ": " Y "Vector" BR ", " Y "Deque" BR " and " Y "List" BR "." << std::endl << std::endl

        		  << " How " Y "Ford-Johnson" BR " algorithm works:" << std::endl << std::endl

				  << "    " Y "1º" BR " Parse and load the arguments into the " B "original" BR " container." << std::endl
				  << "    " Y "2º" BR " Create pairs of elements from the " B "original" BR " container." << std::endl
				  << "    " Y "3º" BR " Sort these pairs using a " B "recursive" BR " sorting algorithm." << std::endl
				  << "    " Y "4º" BR " The sorted pairs are " B "separated" BR " in two containers, " Y "MainChain" BR " and " Y "Pend" BR ". " << std::endl
				  << "    " Y "5º" BR " Calculate " Y "Jacobsthal" BR " numbers to determine the insertion positions in " Y "MainChain" BR "." << std::endl
				  << "    " Y "6º" BR " Perform a " G "binary search" BR " in " Y "MainChain" BR " to find the " B "positions" BR " to insert the elements from " Y "Pend" BR "." << std::endl
				  << "    " Y "7º" BR " Insert the elements from " Y "Pend" BR " into " Y "MainChain" BR " according to the " B "calculated" BR " positions." << std::endl
				  << "    " Y "8º" BR " Insert the " B "last" BR " element into " Y "MainChain" BR " if the number of elements is " B "odd" BR "." << std::endl << std::endl
        		  << " The "G "goal" BR " of this exercise is to showcase the use of " G "advanced sorting" BR " algorithms and to " G "practice" BR << std::endl
				  << " handling large data sets using different " B "containers" BR "." << std::endl << std::endl
        		  << " It highlights the " G "performance" BR " differences between these " B "containers" BR " and emphasizes the importance" << std::endl
				  << " of choosing the " B "appropriate" BR " data structure for specific tasks. " << std::endl << std::endl
				  << G "                 FOR MUCH MORE INFORMATION, PLEASE REFER TO THE SOURCE CODE" << std::endl << std::endl
				  << NC " ——————————————————————————————————————" << std::endl << std::endl
				  << B " Containers:" << std::endl << std::endl
				  << Y "    Vector:" C << std::endl << std::endl
				  << "       Fast access to elements." << std::endl
				  << "       Insertions and deletions can be time-consuming." << std::endl
				  << "       Better cache performance due to memory contiguity." << std::endl << std::endl
				  << Y "    Deque:" C << std::endl << std::endl
				  << "       Allows random access, but generally slower than " Y "Vector" C "." << std::endl
				  << "       Efficient at both ends. More efficient than Vector but less than " Y "List" C " in the middle." << std::endl
				  << "       Not contiguous in memory, but implemented as memory blocks." << std::endl << std::endl
				  << Y "    List:" C << std::endl << std::endl
				  << "       Slow access to elements." << std::endl
				  << "       Fast insertions and deletions." << std::endl
				  << "       Lower cache performance due to lack of memory contiguity." << std::endl << std::endl
				  << B " Conclusion:" BR << std::endl << std::endl
				  << Y "    Vector" BR " is ideal for fast random access operations." << std::endl
				  << Y "    Deque" BR " is a good compromise for efficient operations at both ends and decent random access." << std::endl
				  << Y "    List" BR " is ideal for frequent insertions and deletions in the middle of the container." << std::endl << std::endl
				  << G " Thank you for evaluating me." NC << std::endl << std::endl

        		  << " ======================================" << std::endl << std::endl;


		printContainer(getVector(), "Before");																//	Print unsorted numbers
		printContainer(getVectorMainChain(), "Vector");														//	Print Vector sorted numbers
		printContainer(getDequeMainChain(), "Deque");														//	Print Deque sorted numbers
		printContainer(getListMainChain(), "List");															//	Print List sorted numbers

		std::cout << C " Time to process a range of " B << argc - 1 << C " elements with " Y "std::vector: \t" G << VectorTime << C " ms  \t " B << getVectorComparisons() << C << " comparisons" NC << std::endl;
		std::cout << C " Time to process a range of " B << argc - 1 << C " elements with " Y "std::deque:  \t" G << DequeTime << C " ms  \t " B << getDequeComparisons() << C << " comparisons" NC << std::endl;
		std::cout << C " Time to process a range of " B << argc - 1 << C " elements with " Y "std::list:   \t" G << ListTime << C " ms  \t " B << getListComparisons() << C << " comparisons" NC << std::endl;

		std::cout << std::endl << " ======================================" << std::endl << std::endl;
		std::cout << BR " To run the program with random numbers:" << std::endl << std::endl;
		std::cout << B "    ./PmergeMe" C " $(shuf -i 1-1000 -n 3000 | tr \"\\n\" \" \")" NC << std::endl << std::endl;
		if (getVector().size() > NFILE) {
			std::cout << BR " Compare the sorted files (" G "only displays something if there are differences" BR "):" << std::endl << std::endl;
			std::cout << B "    diff3" C " vector_sorted.txt deque_sorted.txt list_sorted.txt" NC << std::endl << std::endl;
		}
	} catch(const std::exception & e) {
		std::cout << std::endl << " ======================================" << std::endl << std::endl;
		std::cerr << RD " ERROR: " Y "Invalid input" NC << std::endl << std::endl; }
	std::cout << " =======================================" << std::endl << std::endl;
}

/*												WHY IS LIST SO SLOW?

	Storage of Data:
	----------------

std::vector and std::deque store their elements in contiguous memory, which allows fast access to any element via indices.
std::list, on the other hand, stores its elements in linked nodes, meaning that accessing each element requires following node-to-node pointers.
This can be less efficient in terms of random access, such as that required in sorting algorithms and binary search.

	Iterators and Access:
	---------------------

In std::list, iterators are bidirectional, meaning you can move forward or backward in the list, but you cannot directly access an element by its index.
Therefore, operations depending on random access or index manipulation may be slower in std::list compared to other structures that support constant-time random access.

	Algorithm Efficiency:
	---------------------

While sorting and binary search algorithms can theoretically work with std::list, their performance may suffer due to the nature of pointers and manipulation of
linked nodes. For example, in the case of binary search implemented for std::list, although correctly implemented, it may be slower due to how elements are accessed
and manipulated within the list compared to std::vector or std::deque.

	Memory Usage:
	-------------
std::list can consume more memory due to the overhead of storing pointers to link nodes. This can lead to greater memory fragmentation and increased access time due
to the need for more memory allocation and deallocation operations.

*/