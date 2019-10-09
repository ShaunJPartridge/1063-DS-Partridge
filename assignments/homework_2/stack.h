/**
 * File: stack.h
 * Aurhor: Shaun Partridge
 * Course: CMPS 1063 - Prof. Griffin
 * Date: October 8, 2019
 * Description:
 *    Definition of stack class.
 */
#include <fstream>
#include <iostream>
using namespace std;

class Stack {
private:
	int* A;         // Container of items (could make it a list)
	int Top;        // Keeps track of top
	int Size;       // Arrays need a size
	int Count;		// Keeps track of the amount of elements in the array
	int Largest;	// Arrays biggest size
	int Smallest;	// Arrays smallest size
public:

	Stack();        // Default constructor

	Stack(int,int);     // overloaded constructor
	bool Push(int); // Push value onto stack
	int Pop();      // Remove item from top of stack
	int CheckResize(); // Determines if array size is enlarged or reduced
	void Enlarge();	   // Enlarges array size
	void Reduce();	   // Reduces array size
	void Print(ofstream &);   // Prints final result
	bool Empty();   // Is stack empty
	bool Full();    // is stack full

};
