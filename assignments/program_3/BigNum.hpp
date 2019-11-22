//
// Author: SHAUN PARTRIDGE
// Assignment: Program_03
// Date: 21 November 2019
// Title: BigNum.hpp
// Semester: Fall 2019
// Course: CMPS 1063
// Description:  This file is the implementation of a BigNum class that will do
// addition and subtraction using DLList pointers and returning a DLList for 
// the result.
//
#pragma once
#include <string>
#include "DLList.hpp"

using namespace std;

class BigNum {
private:
	// DLList pointers used to create two really large numbers
	DLList *BNum1;
	DLList *BNum2;
public:
	/**
	 * Create a BigNum with an empty list. No value yet.
	 */
	BigNum() {
		BNum1 = new DLList();
		BNum2 = new DLList();
	}

	/**
	 * Function:
	 *		Add
	 * Description:
	 *		Adds two doubly linked lists that represent two big numbers
	 *		and returns a result that is also a doubly linked list.
	 * Params:
	 *		DLList *bnum1
	 *		DLList *bnum2
	 * Return:
	 *      Result list from the addition, which is also a doubly linked list. 
	 */
	DLList* Add(DLList *bnum1, DLList *bnum2) {
		BNum1 = bnum1; // creating copy list of bnum1
		BNum2 = bnum2; // creating copy list of bnum2

		//Initializing variables
		int num1 = 0;
		int num2 = 0;
		int carry = 0;
		int sum = 0;


		DLList* Result = new DLList(); // create a result list that is a doubly
																// linked list
		// while the first list is not empty
		while (!BNum1->Empty()) {
			num1 = BNum1->Delete(); // Num1 gets the value of the node
									 // deleted from the first list
			num2 = BNum2->Delete(); // Num2 gets the value of the node
									// deleted from the second list
			sum = num1 + num2 + carry; // Add both values along with the carry
			carry = sum / 10; //Ex: 12/10 = 1.2, carry = 1
			sum = sum % 10; //Ex: 12 % 10 = 2
									//cout << num1 << " " << num2 << " " << sum << " " << carry << endl;
			Result->InsertFront(sum);// 2 will be inserted in the front of the 
											// result list
		}
		if (carry != 0) {	// If carry does not equal zero then put the
			Result->InsertFront(carry);// carry in front of the current node
		}
		return Result;	// returns the result list
	}

	/**
	 * Function:
	 *		Sub
	 * Description:
	 *		Subtracts two doubly linked lists that represent two big numbers
	 *		and returns a result that is also a doubly linked list.
	 * Params:
	 *		DLList *bnum1
	 *		DLList *bnum2
	 * Return:
	 *      Result list from the subtraction, which is also a doubly linked list.
	 */
	DLList* Sub(DLList* bnum1, DLList* bnum2) {
		BNum1 = bnum1; // Creating copy list of bnum1
		BNum2 = bnum2; // Creating copy list of bnum2

		// Initializing variables
		int num1 = 0;
		int num2 = 0;
		int carry = 0;
		int diff = 0;


		DLList* Result = new DLList(); // Creates a result list that is a doubly
																// linked list
		//while the first list is not empty
		while (!BNum1->Empty()) { 
			num1 = BNum1->Delete();	// Num1 gets the value of the node that
									// was deleted from the first list						
			num2 = BNum2->Delete();//Num2 gets the value of the node that was
								   //	deleted from the second list

			if (num1 + carry >= num2) {// If num1 and the carry is is greater 
										// than or equal to num2
				diff = (num1 + carry) - num2;//do subtraction 
				carry = 0;				// with a zero carry
			}
			else {					// Else if num1 is less than num2
				diff = (num1 + carry + 10) - num2;// add 10 and the carry  
				carry = -1;					// to num1 and do subtraction
			}
						//cout << num1 << " " << num2 << " " << diff << " " << carry << endl;
			Result->InsertFront(diff); // Insert at the front of the result 
										//list the differnce between the nodes
		}
		if (carry != 0) { //If the carry does not equal zero then 
			Result->InsertFront(carry); // put the carry in front of the 
													     //current node
		}
		return Result; // returns the result list
	}

};
