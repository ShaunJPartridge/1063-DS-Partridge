/**
* ListQueue.h
*
* List Bases Queue definitions
*
* Author: Shaun Partridge
* Date: October 14th, 2019
*/

#pragma once
#include <iostream>

using namespace std;

struct Animal {          // Typical node setup for a list. 
	string name;           // string, double, and Animal* data.
	double weight;
	double scary;
	Animal* Next;

	Animal() {             // default constructor
		name = "";
		weight = 0.0;
		scary = 0.0;
		Next = NULL;
	}

	Animal(string n, double w, double s) {      // overloaded constructor
		name = n;
		weight = w;
		scary = s;
		Next = NULL;
	}
};
//Overload "<<" operator for animals
ostream& operator<<(ostream&, const Animal*);

struct Node {
	Animal* A;
	Node* Next;

	// Needs a default constructor
	Node() {
		A = NULL;
		Next = NULL;
	}
	Node(Animal* a) { // Overloaded constructor
		A = a;
		Next = NULL;
	}

};


/**
* List Queue
*
* List Based Queue
*
*/
class ListQueue {
private:
	Node* Front;            // front of the queue (where we remove from)
	Node* Rear;             // rear of the queue (where we add to)
public:
	ListQueue();            // constructor
	void Push(Animal*);         // add animal to rear
	Animal* Pop();              // remove from front
	void Print();           // print for debugging
	bool Empty();           // is queue empty (can't remove from empty queue)
	void PrintPointers();   // added for lecture purposes
	Node* GetFront(Animal*);       // added for lecture purposes
};
