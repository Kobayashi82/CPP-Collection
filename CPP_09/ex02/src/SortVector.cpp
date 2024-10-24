/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SortVector.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:52:04 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/19 19:32:22 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static std::vector<int> Vector;
static std::vector<int> MainChain;
static int comparison_counter = 0;

//	********* VALIDATE NUMBER *********

bool isAllSpace(const std::string & valueStr) {                                                             //  Check if valueStr only contains spaces
    for (size_t i = 0; i < valueStr.length(); ++i) if (!isspace(valueStr[i])) return (false);               //  If something is not isspace() return False
    return (true);                                                                                          //  else return True
}

std::string validateNumber(std::string valueStr) {		        											//	Validate a number as string
    std::size_t k = 0; std::size_t j = valueStr.length();
    while (k < j && std::isspace(valueStr[k])) ++k;															//	Remove leading and trailing spaces
    while (j > k && std::isspace(valueStr[j - 1])) --j;
    valueStr = valueStr.substr(k, j - k);

    if (valueStr.empty()) throw std::runtime_error("Invalid input");										//	Empty strings are not allowed

    for (size_t i = 0; i < valueStr.length(); ++i) {
        if (i == 0 && (valueStr[i] == '+' || valueStr[i] == '-')) i++;										//	Only one '+' or '-' is allowed at the beginning of the number
        else if (!std::isdigit(valueStr[i])) throw std::runtime_error("Invalid input");						//	Only digits are allowed
    } return (valueStr);
}

//	********* (STEP 6) - INSERT FROM PEND TO MAIN CHAIN *********

static int binarySearch(const std::vector<int> & MainChain, int Number, int Start, int End) {				//	If the Number is found, returns its index else returns the index where it could be inserted
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

static void setPositions(std::vector<int> & positions, std::vector<int> & pend) {							//	Function to set positions for insertion based on the Jacobsthal sequence
    size_t currentJacob = 1, pos, lastJacob = 1, i = 3, jacob_i; std::vector<int> Jacob;

    if (pend.empty()) return;																				//	If pend is empty, there's nothing to do
    while ((jacob_i = getJacobNumber(i++)) < pend.size() - 1) Jacob.push_back(jacob_i);						//	Generate Jacobsthal numbers and add them to Jacob until the calculated number exceeds size - 1
	
	//	For example, if pend.size() = 10, Jacob would be {3, 5} because J(3) = 3, J(4) = 5, and J(5) = 11 (which is greater than pend.size())
	//	When transferred to positions, it would be {3, 2, 1, 5, 4, 6, 7, 8, 9, 10}.
	//	Numbers from 3 to 1 are added first, then from 5 to 4, and finally the remaining numbers up to pend.size(), which are from 6 to 10
	
	i = 0;
    while (i < Jacob.size()) {																				//	Iterate through the Jacob to set the positions
        currentJacob = Jacob[i]; positions.push_back(currentJacob); pos = currentJacob - 1;					//	Get Jacob number and add it to positions
        while (pos > lastJacob) positions.push_back(pos--);													//	Fill in positions with values from currentJacob - 1 to lastJacob
        lastJacob = currentJacob; i++;																		//	Update the lastJacob and move to the next Jacob number
    }
    while (currentJacob++ < pend.size()) positions.push_back(currentJacob);									//	Add remaining Jacob numbers to positions up to the pend.size()
}

//	********* (STEP 4) - CREATE MAINCHAIN AND PEND *********

static void createMainChain(const std::vector<std::pair<int, int> > & vecPair) {							//	Separate pairs into Mainchain and pend
    std::vector<int> pend; size_t i = 0, pos; std::vector<int> positions;

	MainChain.push_back(vecPair[i].second);
    while (i < vecPair.size()) {
        MainChain.push_back(vecPair[i].first);																//	Add the first element of the current pair to MainChain
        pend.push_back(vecPair[i].second);																	//	Add the second element of the current pair to pend
        i++;
    } i = 0;

	setPositions(positions, pend);																			//	Generate the positions for insertion

    for (std::vector<int>::iterator it = positions.begin(); it < positions.end(); it++) {
        pos = binarySearch(MainChain, pend[*it - 1], 0, *it + i++);											//	Find the correct position within MainChain
        MainChain.insert(MainChain.begin() + pos, pend[*it - 1]);											//	Insert the number from pend into MainChain
    }
    if (Vector.size() % 2) {																				//	If Vector has an odd number of elements, insert the last element into MainChain
        pos = binarySearch(MainChain, Vector[Vector.size() - 1], 0, MainChain.size() - 1);					//	Find the correct position within MainChain
        MainChain.insert(MainChain.begin() + pos, Vector[Vector.size() - 1]);								//	Insert the last number into MainChain
    }
}

//	********* (STEP 3) - RECURSIVELY SORT PAIRS *********

static void mergePair(std::vector<std::pair<int, int> > & vecPair, int Start, int Middle, int End) {		//	Merges two sorted segments
    size_t a = 0, b = 0;
    
    std::vector<std::pair<int, int> > C_a(vecPair.begin() + Start, vecPair.begin() + Middle + 1);			//	Temp pairs containers to hold the two segments
    std::vector<std::pair<int, int> > C_b(vecPair.begin() + Middle + 1, vecPair.begin() + End + 1);

    while (a < C_a.size() && b < C_b.size()) {																//	Merge until the end of one of the segments
        comparison_counter++;
		if (C_a[a].first <= C_b[b].first) vecPair[Start++] = C_a[a++];										//	Add to the vecPair the smallest between both segments in each iteration
		else vecPair[Start++] = C_b[b++];
	}
    while (a < C_a.size()) vecPair[Start++] = C_a[a++];														//  If there are numbers left in any segment, add them all
	while (b < C_b.size()) vecPair[Start++] = C_b[b++];
}

static void sortPair(std::vector<std::pair<int, int> > & vecPair, int Start, int End) {						//	Recursively sorts vecPair in halves and then merges them
	if (Start == End) return;																				//	If there is only one element, do nothing

	int Middle = Start + ((End - Start) / 2);																//	Calculate the middle index of the segment

	sortPair(vecPair, Start, Middle);																		//	Recursively sort the first half of the segment
	sortPair(vecPair, Middle + 1, End);																		//	Recursively sort the second half of the segment
	mergePair(vecPair, Start, Middle, End);																	//	Merge the two sorted segments
}

//	********* (STEP 1 & 2) - CREATE PAIRS AND SORT THEM *********

static void createSortedPairs() {
    std::vector<std::pair<int, int> > vecPair; int size = Vector.size() / 2; size_t i = 0;					//	Get the half size of vecPair
    
    while (size--) {																						//	Iterate through the vecPair
        int first = Vector[i++]; int second = Vector[i++];
        if (first < second) std::swap(first, second);        												//	For each pair, place the larger number first
		comparison_counter++;
        vecPair.push_back(std::make_pair(first, second));													//	Add it to a vector of pairs to sort it in ascending order based on first
    }
	sortPair(vecPair, 0, vecPair.size() - 1);																//	Sort pairs
	createMainChain(vecPair);																				//	Create Mainchain and pend
}

//	********* (VECTOR CONTAINER) - FORD-JOHNSON SORT ALGORITHM *********

int getVectorComparisons() { return (comparison_counter); }													//	Return the number of comparisons
const std::vector<int> getVector() { return (Vector); }                                                     //  Return Vector
const std::vector<int> getVectorMainChain() { return (MainChain); }                                         //  Return MainChain

void sortVector(int argc, char **argv) {
	
	loadContainer(argc, argv, Vector);																		//	Load container with input

	if (Vector.size() == 1) MainChain.push_back(Vector[0]);													//	If there is only one element, it is already sorted
	else createSortedPairs();																				//	Create and sort pairs
}
