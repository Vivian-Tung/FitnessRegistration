/*
 * List.cpp  ***Using a heap-allocated array***
 * 
 * Class Description: Data collection List ADT class.
 * Class Invariant: Data collection with the following characteristics:
 *                   - value oriented list .
 *                   - elements start at 0. 
 *
 * Date: Sept. 2022 
 * Author: Vivian Tung
 */

#include <iostream>
#include "List.h"  
#include "Member.h"
#include <list>

using std::endl;
using std::cout;

// Constructor
List::List() {
} 

// Destructor
// Description: Destruct a List object, releasing heap-allocated memory.
List::~List() {
   delete[] elements;
   elements = NULL;
}

// Description: Returns the total number of elements currently stored in List.
unsigned int List::getElementCount() const {
	return elementCount;
}

// Description: Insert an element.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted in its proper place in List
//                and elementCount has been incremented.   
bool List::insert( Member& newElement ) {

	//validate -> check if we have space
	bool ableToInsert = (elementCount < CAPACITY);
	
	if (ableToInsert)
	{
		//if it is a new array -> allocate memory 
		if (elementCount == 0) {
			elements = new Member[CAPACITY];
			if (elements == NULL) { // we were able to get memory allocated 
				cout << "new Member[maxElements' failed!" << endl;
				ableToInsert = false;
				return ableToInsert;
			}
			//insert new element 
     		elements[0] = newElement;
     		elementCount++;
     		return ableToInsert; 
		} else { //already existing array 
			// need to check if its already in the data collection 
			//if in data collection return false (ie you werent able to insert because already exists)
			if (search(newElement) != NULL) { //ie search function found a matching number
				return false; 
			}
			
		  	//lets use a while loop to traverse thru to the correct position 
			//while i < getElementCount => compare each phone number with the given phone number 
		  	unsigned int i = 0; //ptr to indicate where to insert the list the member
		  	bool found = false; //flag for if we found the correct position or not for member 
		  	while ((i < elementCount) and  (not found)) {
		  		//if it is smaller -> keep incrementing stop when it is bigger and then shift the elements 
		  		if (newElement.getPhone() < elements[i].getPhone()) {
		  			i++;
		  		} else {
		  			found = true; //to break the loop 
			 	}
	  		}
	  		// shift remaining elements (traverse reverse order to copy elements over to avoid overwriting 
  			for (unsigned int right = elementCount; right > i; right--)  
	 			elements[right] = elements[right - 1];

 			//insert new element 
 			elements[i] = newElement;
 			elementCount++;  
	  	}
   	} 
	return ableToInsert;
}

// Description: Remove an element. 
// Postcondition: toBeRemoved is removed (leaving no gap in the data structure of List)
//                and elementCount has been decremented.		
bool List::remove( Member& toBeRemoved ) {
	//traverse memeber phone numbers until you find then, shift all the members over to left and decrement elementcount

	bool ableToRemove = false;
	
	//check if member valid -> use search function; if it isnt in the list -> return false and check that elementcount >= 1
	
	unsigned int i = 0; //ptr to indicate where to remove the list the member
  	bool found = false;
  	while ((i < elementCount) and  (not found)) {
	//if it is smaller -> keep incrementing stop when it is bigger and then shift the elements 
	if (toBeRemoved.getPhone() < elements[i].getPhone()) {
		i++;
	} else {
		found = true; //to break the loop 
		}
	}
	// shift remaining elements and overwrite to the left
	for (unsigned int right = elementCount-1; right > i; right--)  
		elements[right-1] = elements[right];
	elementCount--;
	ableToRemove = true;
	return ableToRemove;
}  
    
// Description: Remove all elements.
// Postcondition: List is back to the state it was right after being constructed.
void List::removeAll() {
	delete[] elements;
    elements = NULL;
	return;
}

// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
Member* List::search( Member& target ) {
	Member* found = NULL;
	//traverse thru the phone numbers 
	if (elementCount == 0) 
		return found;
		
	int i = 0;
	while (i < elementCount) {
		if (target.getPhone() != elements[i].getPhone()) {
			i++;
		} else {
			found = &elements[i];
			//debug purposes
			//cout << "found " << elements[i] << "address: " << found << endl;
			return found;
		}
	}
	return found;
}

// Description: Prints all elements stored in List by descending order of search key.
// Time Efficiency: O(n)

void List::printList() {
	for (int i = 0; i < elementCount; i++) {
		cout << "" << elements[i].getName() << ", " << elements[i].getPhone() << ", " <<elements[i].getEmail() << ", " << elements[i].getCreditCard()  << endl;
	}
	return;
}  

//  End of implementation file
