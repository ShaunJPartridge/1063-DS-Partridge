/**
* ListQueue.cpp
*
* List Based Queue implementation.
*
* Author: Shaun Partridge
* Date: October 14th, 2019
*/
#pragma once
#include"ListQueue.h"
#include <iostream>
#include <string>

using namespace std;

ostream& operator<<(ostream& os, const Animal* a) {
	os << a->name << ':' << a->weight << ':' << a->scary;
	return os;
}
/**
* ListQueue
* Purpose:
*     Constructs our queue
* Params:
*     void
* Returns:
*     void
*/
ListQueue::ListQueue() {
	Front = Rear = NULL;
}

/**
* Push
* Purpose:
*     Adds item to rear of queue
* Params:
*     int val : item to be added
* Returns:
*     void
*/
void ListQueue::Push(Animal* A) {
	Node* temp = new Node(A);     // allocate new memory

	if (Front == NULL) {              // if list is empty
		Front = Rear = temp;          // point everyone to it
	}
	else {
		Rear->Next = temp;            // otherwise link last node to new one
		Rear = temp;                  // then point Rear to it.
	}

}

/**
* Pop
* Purpose:
*     Removes item from front of queue
* Params:
*     void
* Returns:
*     int : front item
*/
Animal *ListQueue::Pop() {
	Node* temp = Front; // get front data temporarily

	Animal* a = Front->A;            // Point to the front temporarily

	Front = Front->Next;        // Move front to next item 

	delete temp;                   // Now we can delete the old front

	if (!Front) {                 // If front is NULL make rear NULL as well
		Rear = NULL;              // because if front is NULL list is empty!  
	}

	return a;                // return front animal
}

/**
* Print
* Purpose:
*     Prints items in queue for debugging
* Params:
*     void
* Returns:
*     void
*/
void ListQueue::Print() {
	Node* temp = Front;

	while (temp) {			// These lines of
		cout << temp->A;		
		if (temp->Next) {	// code implement a
			cout << "->";	
		}							
		temp = temp->Next;	//  list traversal.
	}
	cout << endl;
}

/**
* Empty
* Purpose:
*     Checks for empty queue. Cant remove from empty queue!
* Params:
*     void
* Returns:
*     bool: true == empty
*/
bool ListQueue::Empty() {
	return Front == NULL;
}

/**
* PrintPointers
* Purpose:
*     Prints front and rear values for lecture purposes
* Params:
*     void
* Returns:
*     void
*/
void ListQueue::PrintPointers() {
	cout << "Front = " << Front << endl;
	cout << "Rear = " << Rear << endl;
}


/**
* GetFront
* Purpose:
*     Returns the front node, for lecture purposes
* Params:
*     void
* Returns:
*     void
*/
Node* ListQueue::GetFront(Animal* A) {
	return Front;
}
