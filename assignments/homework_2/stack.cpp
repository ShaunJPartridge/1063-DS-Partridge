/**
 * File: stack.cpp
 * Aurhor: Shaun Partridge
 * Course: CMPS 1063 - Prof. Griffin
 * Date: October 8, 2019
 * Description:
 *    Class implementation file for our array based stack of ints.
 */

#include <iostream>
#include "stack.h"
using namespace std;

/**
 * Stack constructor
 * Description:
 *    Inits an array of ints and sets top.
 */

Stack::Stack() {
	Size = 10;
	A = new int[Size];
	Top = 0;
	Count = 0;

}

/**
 * Stack constructor
 * Description:
 *    Inits an array of ints to a specified size and sets top.
 * Params:
 *    int s : integer size
 */
Stack::Stack(int start_size, int x) {
	Size = start_size;
	A = new int[Size];
	for (int i = 0; i < Size; i++) {
		A[i] = x;
	}
	Top = 0;
	Count = 0;
	Largest = 0;
	Smallest = 0;
}

/**
 * Push
 * Description:
 *    Adds item to top of stack
 * Params:
 *    int val : integer size
 * Returns:
 *     bool : true = success
 */
bool Stack::Push(int val) {
	if (!Full()) {
		Top++;
		A[Top] = val;
		Count++; // Increment Count if an item is pushed on the stack
		Largest = Count; // Keeps track of Largest for CheckResize calculation
		return true;
	}
	else {
		return false;
	}
}

/**
 * Pop
 * Description:
 *    Removes top of stack and returns it
 * Params:
 *    void
 * Returns:
 *     int : item on stack
 */
int Stack::Pop() {
	if (!Empty()) {
		int temp = 0;
		temp = A[Top];
		Top--;
		Count--; // Decrement Count if an item is removed from the stack
		Smallest = Count; // Keeps track of Smallest for CheckResize calculation
		return temp;
	}
	else {
		// should return a value that implies failuer, but good enough for now
		cout << "Cannot remove item from empty stack" << endl;
	}
	return 0;
}

/**
* CheckResize
* Description:
*		Decides if the array's size needs to be enlarged or reduced
* Params:
*		void
* Returns:
*		int : Largest & Smallest
*/
int Stack::CheckResize() {

		if (Count >= .8 * Size) // if Count >= .8 * Size, enlarge array size
		{										
			Enlarge(); // calls Enlarge() function

			if (Size > Largest) // if Size is greater than Largest
			{							
				Size = Largest;	// Size equals Largest
			}
			return Largest;		// Returns a larger array size	
		}
		if (Count <= .2 * Size)
		{
			Reduce(); // calls Reduce() function

			if (Size < Smallest) // if Size is less than Smallest
			{
				Size = Smallest; // Size equals Smallest
			}
			return Smallest;	 // Returns a smaller array size
		}
	
}

/**
* Enlarge
* Description:
*		Resizes the array to be 1.5 times larger than it previously was
* Params:
*		void
* Returns:
*		void
*/
void Stack::Enlarge() {

	int new_size = Size * 1.5; // Allocating a
	int* Array2 = new int[new_size]; // new larger array

	for (int i = 0; i < Count; i++) { // Copying data from old array 
		Array2[i] = A[i];			// to new array
	}						

	int* temp = A; // int* temp = equals old array
	A = Array2; // Old array equals new array
	delete[] temp; // Delete old array

	Size = new_size; // Array is now bigger
}

/**
* Reduce
* Description:
*		Reduces the array size to half of its previous size
* Params:
*		void
* Returns:
*		void
*/
void Stack::Reduce() {
	int new_size = Size / 2; // Allocating a new
	int* Array2 = new int[new_size]; // smaller array

	for (int i = 0; i < Count; i++) { // Copying data from old array
		Array2[i] = A[i];			// to new array
	}

	int* temp = A; // int* temp = old array
	A = Array2;	// Old array equals new array
	delete[] temp; // Delete old array

	Size = new_size; // Array is now smaller
}

/**
 * Print
 * Description:
 *    Prints out header, array's final size, array's biggest size,
 *    and the remaining values in the array
 * Params:
 *    ofstream& outfile
 * Returns:
 *     void
 */
void Stack::Print(ofstream& outfile)
{	
	// Header
	outfile << "Shaun Partridge" << endl;
	outfile << "October 8th, 2019" << endl;
	outfile << "Homework 2\n\n";

	CheckResize(); // calls CheckResize() function
	outfile << "Stack Size: " << Smallest << endl; // Prints out array's final size
	outfile << "Largest Size: " << Largest << endl; // Prints out array's largest size
	outfile << "Values: ";			// Prints out 
	for (int i = Top; i > 0; i--) { // the remaining elements
		outfile << A[i] << " ";		// in the array
	}
}

/**
 * Empty
 * Description:
 *    Is stack empty
 * Params:
 *    void
 * Returns:
 *    bool : true = empty
 */
bool Stack::Empty() {
	return Top < 0;
}

/**
 * Full
 * Description:
 *    Is stack full
 * Params:
 *    void
 * Returns:
 *    bool : true = full
 */
bool Stack::Full() {
	return (Top == Size - 1);
}
