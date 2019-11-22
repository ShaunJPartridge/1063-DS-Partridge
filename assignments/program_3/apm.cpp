//
// Author: SHAUN PARTRIDGE
// Assignment: Program_03
// Date: 21 November 2019
// Title: apm.cpp
// Semester: Fall 2019
// Course: CMPS 1063
// Description: This program uses a Doubly Linked List class and a BigNum class
// to do arbitrary precison arithmetic. The Doubly Linked List class will be 
// used as the structure being used to do the arithmetic and the BigNum class
// will be used to do the arithmetic. This program will also read in an 
// operator and two strings that each represent a really long integer.
//
#include <iostream>
#include "BigNum.hpp"
#include <fstream>

using namespace std;

int main() {

	BigNum BN; //Instance of BigNum

	// Initializing DDList's Num1, Num2, and Result
	DLList* Num1 = NULL;
	DLList* Num2 = NULL;
	DLList* Result = NULL;
	
	// Initializing variables
	int equations = 0, count = 0;
	char op = ' ';
	string longint1 = " ", longint2 = " ";

	ifstream fin; //infile streaming variable
	ofstream outfile; //outfile streaming variable
	fin.open("input_data.txt");
	outfile.open("output.num");

	// Header of outfile
	outfile << "Shaun Partridge\n";
	outfile << "Program 3\n";
	outfile << "Arbitrary Precision Math\n\n";
	fin >> equations;
	while (!fin.eof()) {

		fin >> op >> longint1 >> longint2; // reads in an operation and 
							// two strings that represent really long integers
		// creating two DLLists with integers
		Num1 = new DLList(longint1); 
		Num2 = new DLList(longint2);
		count++; //increment count
		switch (op) {
		case '+':
			outfile << "Operation " << count << ": " << "Addition\n";
			outfile << " ";
			Num1->Print(outfile);
			outfile << "+";
			Num2->Print(outfile);
			Result = BN.Add(Num1, Num2);
			Result->Print(outfile);
			outfile << endl;
			break;
		case '-':
			outfile << "Operation " << count << ": " << "Subtraction\n";
			outfile << " ";
			Num1->Print(outfile);
			outfile << "-";
			Num2->Print(outfile);
			Result = BN.Sub(Num1, Num2);
			outfile << " ";
			Result->Print(outfile);
			outfile << endl;
			break;
		}
	}

	outfile.close(); // close outfile
	return 0;
}
