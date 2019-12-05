//
// Author: SHAUN PARTRIDGE
// Assignment: Program_04
// Date: 1 December 2019
// Title: CaesarCipher.cpp
// Semester: Fall 2019
// Course: CMPS 1063
// Description: This file is the implementation of a Caesar Cipher class. A caesar cipher
// is basically done by shifting each letter of a message a certain amount of times to
// encrypt the message and vice-versa to decrypt the message. The methods that are in
// this class will do just that. 
//
#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include<cctype>

using namespace std;

class CaesarCipher {
private:
	int shift;
public:
	string str;
	// Default Constructor
	CaesarCipher() {
		shift = 13;
		str = "";
	}

	// Overloaded Constructor 
	CaesarCipher(int s) {
		shift = s;
	}

	/**
	 * Function:
	 *		UpperCase
	 * Description:
	 *		Checks if a char is lower-case and if so upper-case
	 * Params:
	 *		string str
	 * Return:
	 *      A entire string with upper-case letters
	 */
	string UpperCase(string str) {
		int intval = 0;

		for (int i = 0; i < str.length(); i++) {
			intval = (int)str[i];
			// Checks if char is lower-case.
			if (intval >= 97 && intval <= 122) {
				// Converts char to upper-case.
				char ch = str[i] - 32;
				str[i] = ch;

			}
		}
		return str;
	}

	/**
	 * Function:
	 *		SetShift
	 * Description:
	 *		Sets the shift value
	 * Params:
	 *		int s 
	 * Return:
	 *      void
	 */
	void SetShift(int s) {
		shift = s;
	}

	/**
	 * Function:
	 *		GetShift
	 * Description:
	 *		Gets the shift value
	 * Params:
	 *		none
	 * Return:
	 *      Returns the shift value
	 */
	int GetShift() {
		return shift;
	}

	/**
	 * Function:
	 *		ReadPlainText
	 * Description:
	 *		Reads a line from a plain text file into a string 
	 *		that is to be encrypted
	 * Params:
	 *		ifstream& fin
	 *      string data
	 * Return:
	 *      An entire string with plain text
	 */
	string ReadPlainText(ifstream& fin, string data) {
		getline(fin, data);
		return data;
	}

	/**
	 * Function:
	 *		Encrypt
	 * Description:
	 *		Is passed a shift value and a string.
	 *		This shift value will determine what each char of the string
	 *		will be.
	 * Params:
	 *		int shift
	 *		string str
	 * Return:
	 *      An entire encrypted string
	 */
	string Encrypt(int shift, string str) {
		
		// Initializing variables
		int key = GetShift();
		int intval = 0, cypher_val = 0;
		string temp;
		char cypher;

		for (int i = 0; i < str.length(); i++) {
			// Checks if char is a puctuation mark and if so append it to the string.
			if (ispunct(str[i])) {
				temp += str[i];
			}
			else if (!ispunct(str[i])) {
				intval = (int)str[i]; // Gets ASCII value of char.

			// Checks if chars are lowercase and calls
			// UpperCase() to uppercase the chars
				if (intval >= 97 && intval <= 122) {
					UpperCase(str);
				}
				else if (intval == 32) {// If ASCII value is 32, append a space to the string.
					temp += " ";
				}

				// Checks if shift is less than or greater than default shift,
				// convert the char of the string into an integer 
				// then add the shift to the integer value + 65 then convert
				// back to ascii upper case letter by mod 26.

				else if (shift > key || shift < key) {

					//cout << " trash " << endl;
					cypher_val = ((int)str[i] + shift + 65) % 26 + 65;
					cypher = (char)(cypher_val);
					temp += cypher;
				}
				else {// Else do the conversion but adding the "key" default shift.
					cypher_val = ((int)str[i] + key + 65) % 26 + 65;
					cypher = (char)(cypher_val);			// / \
    					 				      // |converts char back to ascii| 
					temp += cypher;
				}
			}
		}
		
		return temp; // return encrypted string
	}

	/**
	 * Function:
	 *		WriteCypherText
	 * Description:
	 *		This function will print out the shift value and encrypted string
	 *		to an output file.
	 * Params:
	 *		int shift
	 *		string str
	 *		ofstream& outfile
	 * Return:
	 *      void
	 */
	void WriteCypherText(int shift, string str, ofstream& outfile) {
		outfile << shift << endl;
		outfile << str << "\n\n"; // Prints out a plain text message per line 
													//along with a space.
	}

	/**
	 * Function:
	 *		ReadCypherText
	 * Description:
	 *		Reads a line from an encrypted file into a string
	 *		that is to be decrypted
	 * Params:
	 *		ifstream& fin
	 *		string data
	 * Return:
	 *      An entire string with encrypted text
	 */
	string ReadCypherText(ifstream& fin, string data) {
		getline(fin, data); // Gets the line of data from input file.
		return data; // Returns the string from the input file.
	}

	/**
	 * Function:
	 *		Decrypt
	 * Description:
	 *		Is passed a shift value and a string.
	 *		This shift value will determine what each char of the string
	 *		will be.
	 * Params:
	 *		int shift
	 *		string str
	 * Return:
	 *      An entire decrypted string
	 */
	string Decrypt(int shift, string str) {

		// Initializing variables
		int key = GetShift();
		int intval = 0, cypher_val = 0;
		string temp;
		char cypher;

		for (int i = 0; i < str.length(); i++) {
			// Checks if char is a puctuation mark and if so append it to the string.
			if (ispunct(str[i])) {
				temp += str[i];
			}
			else if (!ispunct(str[i])) {
				intval = (int)str[i]; // Gets ASCII value of char.

				// Checks if chars are lowercase and calls
				// UpperCase() to uppercase the chars
				if (intval >= 97 && intval <= 122) {
					UpperCase(str);
				}
				else if (intval == 32) {// If ASCII value is 32, append a space to the string.
					temp += " ";
				}

				// Check if shift is less than or greater than "key" default shift,
				// convert the char of the string into an integer 
				// then subtract the shift from the integer value and add 65
				// then convert back to ascii upper case letter by mod 26 and 
				// adding 65.

				else if (shift > key || shift < key) {
					cypher_val = ((int)str[i] - shift + 65) % 26 + 65;
					cypher = (char)(cypher_val);
					temp += cypher;
				}
				else {// Else do the conversion but subtract the "key" default shift
					cypher_val = ((int)str[i] - key + 65) % 26 + 65;
					cypher = (char)(cypher_val);			// / \
    					 				      // |converts char back to ascii| 
					temp += cypher;
				}
			}
		}

		return temp; // return decrypted string

	}

	/**
	 * Function:
	 *		WritePlainText
	 * Description:
	 *		This function will print out the shift value and decrypted string
	 *		to an output file.
	 * Params:
	 *		int shift
	 *		string str
	 *		ofstream& outfile 
	 * Return:
	 *      void
	 */
	void WritePlainText(int shift, string str, ofstream& outfile) {
			outfile << shift << endl;
			outfile << str << "\n\n"; // Prints out a plain text message per line 
													//along with a space.
	}
};
