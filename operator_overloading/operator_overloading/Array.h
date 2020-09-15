#pragma once
#include<iostream>
using namespace std;
class Array
{
	friend ostream& operator<<(ostream&, const Array&);
	friend istream& operator>>(istream&, Array&);
public:
	Array(int size = 10); // default constructor
	Array(const Array&); // copy constructor
	~Array(); // destructor
	int getSize() const; // return size
	const Array& operator=(const Array&); // assignment operator
	bool operator==(const Array&) const; // equality operator
	// inequality operator; returns opposite of == operator
	bool operator!=(const Array& right) const
	{
		return !(*this == right); // invokes Array::operator==
	} // end function operator!=
	// subscript operator for non-const objects returns modifiable lvalue
	int& operator[](int);
	// subscript operator for const objects returns rvalue
	int operator[](int) const;
private:
	int size;
	int* ptr;
};

