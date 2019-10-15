/**
* main.cpp 
* 
* List based queue that holds an animal type
*
* Author: Shaun Partridge
* Date: October 14th, 2019
*/
#include <iostream>
#include <fstream>
#include"ListQueue.h" // include the queue definition

using namespace std;

int main() {

	ifstream fin("animals.txt"); // 
	string name;
	double weight = 0.0;
	double scary = 0.0;
	Animal* a;		// Animal pointer used to hold popped animals
	ListQueue LQ;                 // List based queue object 

	while (!fin.eof()) {
		fin >> name >> weight >> scary;
		a = new Animal(name, weight, scary); // Allocate memory for an animal
		LQ.Push(a);		//Push animal onto the queue
	}

	LQ.Print();  // Print queue

	cout << endl;   

	if (!LQ.Empty())
	{
		a = LQ.Pop(); // removes the front animal from the queue
		cout << "Item: " << a << "\n\n";    // print out items
		
	}
	else
	{
		cout << "Empty queue!" << endl;
	}
	LQ.Print(); // print again to show front removal
	cout << endl;
	LQ.PrintPointers();

	Node* f = LQ.GetFront(a);        // We added this in class JUST to see what front
	cout << f->Next << endl;            // pointed to.
}
