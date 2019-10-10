/**
 * Lecture 07
 *
 * List based Stack that holds an animal type
 *
 * Author: Shaun Partridge
 * Date: October 10th, 2019
 */
#include <fstream>        
#include <iostream>
#include "ListStack.h" // include our stack definition

using namespace std;

int main() {
	ifstream fin("animals.txt");  // input file of animal info            
	string name;
	double weight = 0.0;	
	double scary = 0.0;
	Animal* a;                    // animal pointer used to hold popped animals
	ListStack LS;                 // List based stack object

	// While still animals in the file
	while (!fin.eof()) {
		fin >> name >> weight >> scary;
		a = new Animal(name, weight, scary);                         // allocate memory for an animal
		  // load animal with file data
		LS.Push(a);                               // push animal onto the stack
	}


	LS.Print();             // Print the stack

	cout << endl;           // ummm

	a = LS.Pop();           // get animal off top of stack

	cout << a << endl;      // print animal (cout operator overloaded)

	a = LS.Pop();           // get animal off top of stack again

	cout << a << endl;      // print animal (cout operator overloaded)

	LS.Print();             // print the stack
}
