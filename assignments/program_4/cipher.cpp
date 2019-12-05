//
// Author: SHAUN PARTRIDGE
// Assignment: Program_04
// Date: 1 December 2019
// Title: cipher.cpp
// Semester: Fall 2019
// Course: CMPS 1063
// Description: This is the main driver of a program
// that will use a Caesar Cipher class to read from an encrypted file and write a 
// decrypted message to an outfile.This outfile will then be used as a plain text
// file and be read from to encrypt the file.
//
#include<string>
#include<iostream>
#include<fstream>
#include "CaesarCipher.hpp"

using namespace std;

int main(int argc, char** argv) {

	CaesarCipher CC;// Instance of CaesarCipher class

	ifstream fin;
	ofstream outfile;

	fin.open("encrypted.txt");// Open input file of encrypted text
	outfile.open("decrypted.txt");// Open outfile for decrypted text
	
	// Declaring variables
	string rline;
	string cyph_text = "";
	string plain_text = "";
	string message = "";
	string str_message_count = "";
	int int_message_count = 0;
	string str_shift = "";
	int int_shift = 0;

	getline(fin, str_message_count);// Gets string containing the amount 
										//of messages to be decrypted
	int_message_count = stoi(str_message_count);// Converts value to integer.
	
	// Header of output file
	outfile << "SHAUN PARTRIDGE\n";
	outfile << "12-1-19\n";
	outfile << "Program 4 Output\n";
	outfile << int_message_count << "\n\n";
  
  // This for loop will be used to decrypt the file, "encrypted.txt"
  // and printed out to the file "decrypted.txt".
	for (int i = 0; i < int_message_count; i++) {

		getline(fin, str_shift);// Gets the shift value from the file
		int_shift = stoi(str_shift);// Converts the shift value from a string to int
		cyph_text = CC.ReadCypherText(fin, message);// Reads a message into a string
		rline = CC.Decrypt(int_shift, cyph_text); // Decrypts message into a string
		CC.WritePlainText(int_shift, rline, outfile);// Prints out decrypted message
	}
	
	fin.close(); // Close input file
	outfile.close(); // Close output file

	fin.open("decrypted.txt"); // Open input file
	outfile.open("ciphertext.txt"); // Open output file

	// Header of outfile using getline
	getline(fin, message);
	outfile << message << endl;
	getline(fin, message);
	outfile << message << endl;
	getline(fin, message);
	outfile << message << endl;

	getline(fin, str_message_count);// Gets string containing amount of messages 
													// to be encrypted.
	int_message_count = stoi(str_message_count);// Converts value to integer.
	outfile << int_message_count << "\n\n";

  // This for loop will be used to encrypt the file, "decrypted.txt"
  // and print out to the file "ciphertext.txt".
	for (int i = 0; i < int_message_count; i++) {

		getline(fin, message);// Gets a space from the file
		getline(fin, str_shift);// Gets the shift value from the file
		int_shift = stoi(str_shift);//Converts the shift value from string to int
		plain_text = CC.ReadPlainText(fin, message);// Reads a message into a string
		rline = CC.Encrypt(int_shift, plain_text);// Encrypts message into a string
		CC.WriteCypherText(int_shift, rline, outfile);// Prints out encrypted message
	}

	fin.close(); // Close input file
	outfile.close();// Close output file
	
	return 0;
}
