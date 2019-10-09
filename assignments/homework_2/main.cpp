/**
* File: main.cpp
* Author: Shaun Partridge
* Course: CMPS 1063 - Prof. Griffin
* Date: October 8, 2019
* Description:
*	Main driver of an Array based implementation of a stack.
*
*/

#include <iostream>
#include "stack.h"
#include <fstream>

using namespace std;

/*
* Main Program
*
*/
int main() {
	
	ifstream fin;
	ofstream outfile;
	fin.open("input_data.txt");
	outfile.open("stack_out.dat");

	char op;
	int val = 0;

	Stack S1; // Instance of Stack default constructor
	

	while (!fin.eof()) { // while not end of file
		fin >> op >> val;  // read in an operator and value

		if (op == '+')	// if operator equals 
		{					// '+', push
			S1.Push(val); // a value onto the stack
		}
		if (op == '-') // if operator equals
		{					// '-', pop
			S1.Pop();	  // a value from the stack
		}
		
	}

	S1.Print(outfile); // calls Print() and prints to outfile

	outfile.close();
	return 0;

}
