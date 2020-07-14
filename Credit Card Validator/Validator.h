#pragma once

#include <string>
	

using namespace std;

class Validator
{
public:

	Validator(string &key); //Constructor
	//int or bool: Check if only nums
	bool CheckNums(string& key); // Takes in key, T if all nums/valid length, F if not
	//string: ID Institution
	string IdInstitution(int key); //Figure out how credit cards do this....
	//bool: Luhn Algorithm
	bool LuhnAlgorithm(); // T if alg returns a multiple of 10, F if not

	void print();
private:
	unsigned int MAX;
	int *_checkNums;
	int _checkSum;
};
