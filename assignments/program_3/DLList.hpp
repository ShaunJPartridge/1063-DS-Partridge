//
// Author: SHAUN PARTRIDGE
// Assignment: Program_03
// Date: 21 November 2019
// Title: DLList.hpp
// Semester: Fall 2019
// Course: CMPS 1063
// Description: This file contains the definiton and implementation of a DLList
// class. This class will create a doubly linked list with an integer in each 
// node and be used to perform aribitrary precision arithmetic.
//
#pragma once
#include <iostream>
#include <fstream>

using namespace std;

struct Node {
	int data;
	Node* Next; // Pointer for Next
	Node* Prev; // Pointer for Prev

	// Constructor for Node
	Node(int d) {
		data = d;
		Next = NULL;
		Prev = NULL;
	}
};

class DLList {
private:
	int Count;                // Count of items in list
	int _DeleteTail();	//
public:
	Node* Head;               // Head of list pointer
	Node* Tail;					// Tail of list pointer
	DLList();                   // Constructor
	DLList(string);				// Constructor that is passed a string
	DLList(const DLList&);     // Copy Constructor
	~DLList();                  // Destructor
	int Size();
	void InsertFront(int);
	void InsertBack(int);
	void Print(ofstream&);
	int Delete();
	bool Empty();
};

/**
 * Public Default Constructor
 */
DLList::DLList() {
	Head = Tail = NULL; // Initializing Head and Tail
	Count = 0; // Initializing Count
}

/**
  * Create a BigNum from a string. Each digit will be stored in a Node.
  */
DLList::DLList(string big_number) {
	Head = Tail = NULL;
	Count = 0;

	for (int i = 0; i < big_number.size(); i++) {
		InsertBack(big_number[i] - 48); // parsing a string and putting
	}						// a digit in each node
}

/**
 * Function:
 *		Empty()
 * Description:
 *		returns true if list is empty
 * Params:
 *		void
 * Return:
 *		bool
 */
bool DLList::Empty() {
	return ((!Head) && (!Tail));
}

/**
 * Public Copy Constructor
 *      constructs a new list with values from another list.
 */
DLList::DLList(const DLList& list) {
	Head = Tail = NULL; // Initialize pointers like always
	Count = 0;

	// Point to "Other" lists head. Even though its private we
	// can access it beacuase we are in a class of the same type.
	Node* Other = list.Head;

	// Travers the other list
	while (Other) {
		// Insert values into new nodes in this list.
		InsertBack(Other->data);
		Other = Other->Next;
	}
}

/**
 * Public Destructor
 */
DLList::~DLList() {
	Node* temp = Head;

	while (temp) {
		temp = temp->Next;
		delete Head;
		Head = temp;
	}
}

/**
 * Function: 
 *		InsertFront
 * Description:
 *		Adds item to head of list by calling private method with a node.
 * Params:
 *      int data : item to be placed in list
 * Return:
 *		void
 */
void DLList::InsertFront(int data) {
	// Allocating new memory
	Node* Temp = new Node(data);

	if (!Head) {// If there is no Head,
		Head = Temp; // then Temp = Head and Tail 
		Tail = Temp;
	}
	else { // Else, insert new node "Temp", in front of the old Head of list
		Head->Prev = Temp;
		Temp->Next = Head;
		Head = Temp;
	}
	Count++; // Increment Count
}

/**
 * Function:
 *		InsertBack
 * Description:
 *		Adds item to tail of list by calling private method with a node.
 * Params:
 *		int data : item to be placed in list
 * Return:
 *     void
 */
void DLList::InsertBack(int data) {
	// Allocate new memory
	Node* Temp = new Node(data);

	if (!Head) {// If there is no Head, then
		Head = Temp; // Temp = Head and Tail
		Tail = Temp;
	}
	else { // Else, insert new node "Temp", behind Head of the list
		Tail->Next = Temp;
		Temp->Prev = Tail;
		Tail = Temp;
	}
	Count++; // Increment Count
}

/**
 * Function:
 *		Public Print
 * Description:
 *		Prints list to outfile from head to tail
 * Params:
 *      ofstream& outfile
 * Returns:
 *      void
 */
void DLList::Print(ofstream& outfile) {
	Node* Temp = Head; // create temp pointer to traverse through list

	while (Temp) { // while temp
		outfile << Temp->data; // print out data
		Temp = Temp->Next; // go to next node
	}
	outfile << endl;
}

/**
 * Function:
 *		Private _DeleteTail
 * Description:
 *		Deletes last node in list
 * Params:
 *      void
 * Returns:
 *      int : the deleted tail node's data
 */
int DLList::_DeleteTail() {
	int val = -1;
	if (Tail) {
		Node* Temp = Tail; // temp pointer equals Tail
		val = Tail->data;
		if (Tail == Head) { // delete Head and Tail if there is only one node
			Tail = Head = NULL;      // in list
			delete Temp;
		}
		else { // delete Tail node if 

			Tail = Tail->Prev; // tail points to tail->prev
			Tail->Next = NULL; // tail->next points to NULL
			delete Temp; // delete temp or Tail
		}
		Count--; //decrement Count
	}
	return val;// return deleted tail node's data
}

/**
 * Function:
 *		Delete
 * Description:
 *		Deletes last node in list
 * Params:
 *      void
 * Returns:
 *      int : the deleted tail node's data
 */
int DLList::Delete() {
	return _DeleteTail();
}

/**
 * Function:
 *		Size
 * Description:
 *		Returns size of list
 * Params:
 *     void
 * Returns:
 *     int : the Count of how many nodes are inserted in the DLList
 */
int DLList::Size() {
	return Count;
}
