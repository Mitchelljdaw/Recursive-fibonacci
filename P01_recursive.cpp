// Class: CS 2420 
// Date Written: 1/17/2017
// Description: Recusrsion
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.

#include "stdafx.h"
#include "FileErrors.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

//Function Name: Fib
//Purpose:Calculates the fib sequence of a number that is read from a file recusrsivly
//Parameters: interger value
int Fib(const int n);


//Function Name: nonFib
//Purpose:Calculates the fib sequence of a number that is read from a file non recusrsivly
//Parameters: interger value
int nonFib(int n);


void main()
{
	string number;
	string file;
	//create objet for error handling
	FileErrors _exceptions;
	//ask user what file they would like to read from
	cout << "Please enter the name of the file from which you would like ot read:";
	cin >> file;
	//declare ifstream to read file
	ifstream _readFile;
	//Open file
	try {

		_readFile.open(file);
		if (_readFile.fail()) {
			cout << "File not found" << endl;
		}
		else {
			cout << "  Recursive Work " << endl;
			while (!_readFile.eof()) {
				getline(_readFile, number);
				cout << number << "               " << Fib(stoi(number)) << endl;
			}
			cout << "  Itirative Work  " << endl;
			//Get to the beggining of the file to read through it again
			_readFile.clear();
			_readFile.seekg(0, _readFile.beg);
			while (!_readFile.eof()) {
				getline(_readFile, number);
				cout << number << "               " << nonFib(stoi(number)) << endl;
			}
			_readFile.close();
		}
		}		
	catch (FileErrors &e) {
		cout << e.GetErrorMessage(OPEN_ERROR) << endl;
	}
	system("PAUSE");
}





int Fib(int n) {
	if (n <= 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	return Fib(n - 2) + Fib(n - 1);
}

int nonFib(int n) {
	int cur = 0;
	int num1 = 0;
	int num2 = 1;
	if (n <= 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	for (int i = 0; i < n; i++)
	{
		cur = num1 + num2;
		num2 = num1;
		num1 = cur;
	}
	return cur;
}


void openFile(ifstream& in, const string& _name)
{
	FileErrors _exceptions;
	//Try and open file
	in.open(_name);
	if (in.fail()) {
		throw _exceptions.GetErrorMessage(OPEN_ERROR);
	}
}