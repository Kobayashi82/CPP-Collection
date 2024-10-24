/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SortDeque.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 23:24:40 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/11 23:58:16 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static std::deque<int> Deque;
static std::deque<int> MainChain;
static int comparison_counter = 0;

//	********* (STEP 6) - INSERT FROM PEND TO MAIN CHAIN *********

static int binarySearch(const std::deque<int> & MainChain, int Number, int Start, int End) {				//	If the Number is found, returns its index else returns the index where it could be inserted
    int Middle = 0;

    while (Start <= End) {
        Middle = Start + ((End - Start) / 2);																//	Calculate the Middle of the current search range
		comparison_counter++;
        if (Number == MainChain[Middle]) return (Middle);													//	If the Number is found at the Middle index, return this index
        comparison_counter++;
		if (Number > MainChain[Middle]) Start = Middle + 1;													//	If the Number is greater than the value at Middle, search the right half
        else End = Middle - 1;																				//	Otherwise, search the left half
    }																										//	If the loop exits, the Number was not found
    comparison_counter++;
	if (Number > MainChain[Middle]) return (Middle + 1); else return (Middle);								//	Determine if the Number should be inserted before or after the last Middle
}

//	********* (STEP 5) - GENERATE POSITIONS FOR INSERTION *********

static int getJacobNumber(int n) {																			//	Jacobsthal numbers are defined by J(n) = J(n - 1) + (2 * J(n - 2))
    if (n == 0 || n == 1) return (n);																		//	Base case for J(0) or J(1)
    return (getJacobNumber(n - 1) + (2 * getJacobNumber(n - 2)));											//	Recursive call to get the current number
}

static void setPositions(std::deque<int> & positions, std::deque<int> & pend) {								//	Function to set positions for insertion based on the Jacobsthal sequence
    size_t currentJacob = 1, pos, lastJacob = 1, i = 3, jacob_i; std::deque<int> Jacob;

    if (pend.empty()) return;																				//	If pend is empty, there's nothing to do
    while ((jacob_i = getJacobNumber(i++)) < pend.size() - 1) Jacob.push_back(jacob_i);						//	Generate Jacobsthal numbers and add them to Jacob until the calculated number exceeds size - 1
	
	//	For example, if pend.size() = 10, Jacob would be {3, 5} because J(3) = 3, J(4) = 5, and J(5) = 11 (which is greater than pend.size())
	//	When transferred to positions, it would be {3, 2, 1, 5, 4, 6, 7, 8, 9, 10}.
	//	Numbers from 3 to 1 are added first, then from 5 to 4, and finally the remaining numbers up to pend.size(), which are from 6 to 10

	while (!Jacob.empty()) {																				//	Iterate through the Jacob to set the positions
		currentJacob = Jacob.front(); Jacob.pop_front();
		positions.push_back(currentJacob); pos = currentJacob - 1;											//	Get Jacob number and add it to positions
		while (pos > lastJacob) positions.push_back(pos--);													//	Fill in positions with values from currentJacob - 1 to lastJacob
		lastJacob = currentJacob;																			//	Update the lastJacob and move to the next Jacob number
	}
	while (currentJacob++ < pend.size()) positions.push_back(currentJacob);									//	Add remaining Jacob numbers to positions up to the pend.size()
}


//	********* (STEP 4) - CREATE MAINCHAIN AND PEND *********

static void createMainChain(const std::deque<std::pair<int, int> > & deqPair) {								//	Separate pairs into Mainchain and pend
    std::deque<int> pend; size_t i = 0, pos; std::deque<int> positions;

	MainChain.push_back(deqPair[i].second);
    while (i < deqPair.size()) {
        MainChain.push_back(deqPair[i].first);																//	Add the first element of the current pair to MainChain
        pend.push_back(deqPair[i].second);																	//	Add the second element of the current pair to pend
        i++;
    } i = 0;
	
	setPositions(positions, pend);																			//	Generate the positions for insertion
	
    for (std::deque<int>::iterator it = positions.begin(); it < positions.end(); it++) {
        pos = binarySearch(MainChain, pend[*it - 1], 0, *it + i++);											//	Find the correct position within MainChain
        MainChain.insert(MainChain.begin() + pos, pend[*it - 1]);											//	Insert the number from pend into MainChain
    }
    if (Deque.size() % 2) {																					//	If Deque has an odd number of elements, insert the last element into MainChain
        pos = binarySearch(MainChain, Deque[Deque.size() - 1], 0, MainChain.size() - 1);					//	Find the correct position within MainChain
        MainChain.insert(MainChain.begin() + pos, Deque[Deque.size() - 1]);									//	Insert the last number into MainChain
    }
}

//	********* (STEP 3) - RECURSIVELY SORT PAIRS *********

static void mergePair(std::deque<std::pair<int, int> > & deqPair, int Start, int Middle, int End) {	    	//	Merges two sorted segments
    size_t a = 0, b = 0;
    
    std::deque<std::pair<int, int> > C_a(deqPair.begin() + Start, deqPair.begin() + Middle + 1);		    //	Temp pairs containers to hold the two segments
    std::deque<std::pair<int, int> > C_b(deqPair.begin() + Middle + 1, deqPair.begin() + End + 1);

    while (a < C_a.size() && b < C_b.size()) {																//	Merge until the end of one of the segments
        comparison_counter++;
		if (C_a[a].first <= C_b[b].first) deqPair[Start++] = C_a[a++];								    	//	Add to deqPair the smallest between both segments in each iteration
		else deqPair[Start++] = C_b[b++];
	}
    while (a < C_a.size()) deqPair[Start++] = C_a[a++];													    // If there are numbers left in any segment, add them all
	while (b < C_b.size()) deqPair[Start++] = C_b[b++];
}

static void sortPair(std::deque<std::pair<int, int> > & deqPair, int Start, int End) {				    	//	Recursively sorts deqPair in halves and then merges them
	if (Start == End) return;																				//	If there is only one element, do nothing

	int Middle = Start + ((End - Start) / 2);																//	Calculate the middle index of the segment

	sortPair(deqPair, Start, Middle);																		//	Recursively sort the first half of the segment
	sortPair(deqPair, Middle + 1, End);																	    //	Recursively sort the second half of the segment
	mergePair(deqPair, Start, Middle, End);																    //	Merge the two sorted segments
}

//	********* (STEP 1 & 2) - CREATE PAIRS AND SORT THEM *********

static void createSortedPairs() {
    std::deque<std::pair<int, int> > deqPair; int size = Deque.size() / 2; size_t i = 0;					//	Get the half size of the container
    
    while (size--) {																						//	Iterate through the container
        int first = Deque[i++]; int second = Deque[i++];
        if (first < second) std::swap(first, second);        												//	For each pair, place the larger number first
		comparison_counter++;
        deqPair.push_back(std::make_pair(first, second));													//	Add it to a deque of pairs to sort it in ascending order based on first
    }
	sortPair(deqPair, 0, deqPair.size() - 1);																//	Sort pairs
	createMainChain(deqPair);																				//	Create Mainchain and pend
}

//	********* (DEQUE CONTAINER) - FORD-JOHNSON SORT ALGORITHM *********

int getDequeComparisons() { return (comparison_counter); }													//	Return the number of comparisons
const std::deque<int> getDeque() { return (Deque); }                                                        //  Return Deque
const std::deque<int> getDequeMainChain() { return (MainChain); }                                           //  Return MainChain

void sortDeque(int argc, char **argv) {
	
	loadContainer(argc, argv, Deque);																		//	Load container with input

	if (Deque.size() == 1) MainChain.push_back(Deque.front());												//	If there is only one element, it is already sorted
	else createSortedPairs();																				//	Create and sort pairs
}
