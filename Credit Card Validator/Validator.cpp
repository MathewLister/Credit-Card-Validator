#include <string>
#include <iostream>

#include "Validator.h"

using namespace std;

Validator::Validator(string& key)
{
	MAX = key.length();
	//convert last char to asci code for int
	_checkSum = key[MAX - 1] - '0';

	//Create dynamic aray for numbers
	_checkNums = new int[MAX];
	for (int i = 0; i < MAX; i++)
	{	
		_checkNums[i] = key[i] - '0';
	}
}

//int or bool: Check if only nums
bool Validator::CheckNums(string& key) // Takes in key, T if all nums/valid length, F if not
{
	if (key.length() > MAX)
		return false;

}

bool Validator::LuhnAlgorithm()
{
	int sum = 0;
	//start at end -> double every second digit
	for (int i = MAX - 1; i >= 0; i--)
	{
		sum += _checkNums[i]; //Only double every second digit
			i--;
		_checkNums[i] *=  2;
		if (_checkNums[i] > 9) //if doubleing results are greater than 9 -> add digits to product to get single digit
		{
			_checkNums[i] -= 9;
		}
		sum += _checkNums[i]; //take the sum of all digits
	}
	if (sum % 10 == 0)
		return true;

	return false;
}

void Validator::print()
{
	for (int i = 0; i < MAX; i++)
	{
		cout << _checkNums[i];
	}
	cout << endl;	
	cout << "CHECKSUM: " << _checkSum << endl;
}