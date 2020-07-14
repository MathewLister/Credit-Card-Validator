#include <string>
#include <iostream>

#include "Validator.h"
using namespace std;

int main()
{
	string sampleWrong = "1234567891234561";
	string sampleRight = "4556737586899855";
	string rightTwo = "5590340906115964";
	string cardNumber;
	cout << "Enter card number: ";
	cin >> cardNumber;
	cout << endl;

	Validator card(cardNumber);

	card.print();
	cout << endl;
	cout << endl;
	cout << endl;

	if (card.LuhnAlgorithm() == true)
	{
		cout << "VALID" << endl;
		card.print();
		return 0;
	}
	card.print();
	cout << endl;
	cout << "INVALID";
	return 0; 
}