#pragma once
#include <iostream>
#include <string>
using namespace std;
class PhoneNumber
{
public:
	friend ostream& operator << (ostream&, const PhoneNumber&); // be global because the class is right operand
	friend istream &operator >> (istream&, PhoneNumber&);
private:
	string areaCode; // 3-digit area code
	string exchange; // 3-digit exchange
	string line; // 4-digit line
};

