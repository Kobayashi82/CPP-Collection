/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SortList.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 23:24:40 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 13:50:21 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static std::list<int> List;
static std::list<int> MainChain;
static int comparison_counter = 0;

//	********* (STEP 6) - INSERT FROM PEND TO MAIN CHAIN *********

static int binarySearch(std::list<int> & MainChain, int Number, int Start, int End) {
    int Middle = 0; std::list<int>::iterator itMiddle;
   
    while (Start <= End) {
        Middle = Start + ((End - Start) / 2);																//	Calculate the Middle of the current search range
        itMiddle = MainChain.begin(); std::advance(itMiddle, Middle);
		comparison_counter++;
        if (Number == *itMiddle) return (Middle);															//	If the Number is found at the Middle index, return this index
		comparison_counter++;
        if (Number > *itMiddle) Start = Middle + 1;															//	If the Number is greater than the value at Middle, search the right half
        else End = Middle - 1;																				//	Otherwise, search the left half
    }																										//	If the loop exits, the Number was not found
	comparison_counter++;
    itMiddle = MainChain.begin(); std::advance(itMiddle, Middle);
    if (itMiddle != MainChain.end() && Number > *itMiddle) return (Middle + 1); else return (Middle);		//	Determine if the Number should be inserted before or after the last Middle
}

//	********* (STEP 5) - GENERATE POSITIONS FOR INSERTION *********

static int getJacobNumber(int n) {																			//	Jacobsthal numbers are defined by J(n) = J(n - 1) + (2 * J(n - 2))
    if (n == 0 || n == 1) return (n);																		//	Base case for J(0) or J(1)
    return (getJacobNumber(n - 1) + (2 * getJacobNumber(n - 2)));											//	Recursive call to get the current number
}

static void setPositions(std::list<int> & positions, std::list<int> & pend) {									//  Function to set positions for insertion based on the Jacobsthal sequence
    size_t currentJacob = 1, pos, lastJacob = 1, i = 3, jacob_i; std::list<int> Jacob;

    if (pend.empty()) return; 																				//  If pend is empty, there's nothing to do
    while ((jacob_i = getJacobNumber(i++)) < pend.size() - 1) Jacob.push_back(jacob_i); 					//  Generate Jacobsthal numbers and add them to Jacob until the calculated number exceeds size - 1

	// For example, if pend.size() = 10, Jacob would be {3, 5} because J(3) = 3, J(4) = 5, and J(5) = 11 (which is greater than pend.size() - 1)
	//	When transferred to positions, it would be {3, 2, 1, 5, 4, 6, 7, 8, 9, 10}.
	//	Numbers from 3 to 1 are added first, then from 5 to 4, and finally the remaining numbers up to pend.size(), which are from 6 to 10
    i = 0;
    while (i < Jacob.size()) { 																				//  Iterate through Jacob to set the positions
        std::list<int>::iterator it = Jacob.begin(); std::advance(it, i);									//  Move iterator to the current position
        currentJacob = *it; positions.push_back(currentJacob); pos = currentJacob - 1; 						//  Get Jacob number and add it to positions
        while (pos > lastJacob) positions.push_back(pos--); 												//  Fill in positions with values from currentJacob - 1 to lastJacob
        lastJacob = currentJacob; i++; 																		//  Move to the next Jacob number
    }
    while (currentJacob++ < pend.size()) positions.push_back(currentJacob); 								//  Add remaining Jacob numbers to positions up to the pend.size()
}

//	********* (STEP 4) - CREATE MAINCHAIN AND PEND *********

static void createMainChain(const std::list<std::pair<int, int> > & lstPair) {								//	Separate pairs into Mainchain and pend
    std::list<int> pend; size_t i = 0; std::list<int> positions;

	MainChain.push_back(lstPair.begin()->second);
    for (std::list<std::pair<int, int> >::const_iterator itPair = lstPair.begin(); itPair != lstPair.end(); ++itPair) {
        MainChain.push_back(itPair->first);																	// Add the first element of the current pair to MainChain
        pend.push_back(itPair->second);																		// Add the second element of the current pair to pend
    } i = 0;

    setPositions(positions, pend);																			//	Generate the positions for insertion

    for (std::list<int>::iterator itPos = positions.begin(); itPos != positions.end(); ++itPos) {
    	std::list<int>::iterator itPend = pend.begin(); std::advance(itPend, *itPos - 1);
        int pos = binarySearch(MainChain, *itPend, 0, *itPos + i++);										//	Find the correct position within MainChain
        std::list<int>::iterator itInsert = MainChain.begin(); std::advance(itInsert, pos);
        MainChain.insert(itInsert, *itPend);																//	Insert the number from pend into MainChain
    }

    if (List.size() % 2 != 0) {																				//	If List has an odd number of elements, insert the last element into MainChain
        std::list<int>::iterator itPend = List.end(); itPend--;
        int pos = binarySearch(MainChain, *itPend, 0, MainChain.size() - 1);      					        //	Find the correct position within MainChain
        std::list<int>::iterator itInsert = MainChain.begin(); std::advance(itInsert, pos);
        MainChain.insert(itInsert, *itPend);                                                   				//	Insert the last number into MainChain
    }
}

//	********* (STEP 3) - RECURSIVELY SORT PAIRS *********

static void mergePair(std::list<std::pair<int, int> > & lstPair, int Start, int Middle, int End) {			//	Merges two sorted segments

 	std::list<std::pair<int, int> >::iterator itStart = lstPair.begin(); std::advance(itStart, Start);
    std::list<std::pair<int, int> >::iterator itMiddle = lstPair.begin(); std::advance(itMiddle, Middle + 1);
    std::list<std::pair<int, int> >::iterator itMiddleNext = lstPair.begin(); std::advance(itMiddleNext, Middle + 1);
    std::list<std::pair<int, int> >::iterator itEnd = lstPair.begin(); std::advance(itEnd, End + 1);

    std::list<std::pair<int, int> > C_a(itStart, itMiddleNext);												//	Temp pairs containers to hold the two segments
    std::list<std::pair<int, int> > C_b(itMiddleNext, itEnd);

    std::list<std::pair<int, int> >::iterator a = C_a.begin();
    std::list<std::pair<int, int> >::iterator b = C_b.begin();

    std::list<std::pair<int, int> >::iterator pos = lstPair.begin(); std::advance(pos, Start);				//	Iterator for lstPair

    while (a != C_a.end() && b != C_b.end()) {																//	Merge until the end of one of the segments
		comparison_counter++;
        if (a->first <= b->first) { *pos = *a; ++pos; ++a; }												//	Add to lstPair the smallest between both segments in each iteration
        else { *pos = *b; ++pos; ++b; }
    }

    while (a != C_a.end()) { *pos = *a; ++pos; ++a; }														// If there are numbers left in any segment, add them all
    while (b != C_b.end()) { *pos = *b; ++pos; ++b; }
}

static void sortPair(std::list<std::pair<int, int> > & lstPair, int Start, int End) {						//	Recursively sorts lstPair in halves and then merges them
    if (Start >= End) return;																				//	If there is only one element, do nothing

    int Middle = Start + (End - Start) / 2;																	//	Calculate the middle index of the segment

    sortPair(lstPair, Start, Middle);																		//	Recursively sort the first half of the segment
    sortPair(lstPair, Middle + 1, End);																		//	Recursively sort the second half of the segment
    mergePair(lstPair, Start, Middle, End);																	//	Merge the two sorted segments
}

//	********* (STEP 1 & 2) - CREATE PAIRS AND SORT THEM *********

static void createSortedPairs() {
    std::list<std::pair<int, int> > lstPair; int size = List.size() / 2;									//	Get the half size of lstPair

    while (size--) {																						//	Iterate through lstPair
        int first = List.front(); List.pop_front();
        int second = List.front(); List.pop_front();
        if (first < second) std::swap(first, second);        												//	For each pair, place the larger number first
		comparison_counter++;
        lstPair.push_back(std::make_pair(first, second));													//	Add it to a list of pairs to sort it in ascending order based on first
    }

    sortPair(lstPair, 0, lstPair.size() - 1);																//	Sort pairs
    createMainChain(lstPair);																				//	Create Mainchain and pend
}

//	********* (LIST CONTAINER) - FORD-JOHNSON SORT ALGORITHM *********

int getListComparisons() { return (comparison_counter); }													//	Return the number of comparisons
const std::list<int> getList() { return (List); }                                                           //  Return List
const std::list<int> getListMainChain() { return (MainChain); }                                             //  Return MainChain

void sortList(int argc, char **argv) {
    loadContainer(argc, argv, List);																		//	Load container with input

    if (List.size() == 1) MainChain.push_back(List.front());												//	If there is only one element, it is already sorted
    else createSortedPairs();																				//  Create and sort pairs
}
