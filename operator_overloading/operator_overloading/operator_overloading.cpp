// operator_overloading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PhoneNumber.h" //stream insertion and extraction operators
#include "Array.h"
#include "Date.h"
void outputArray(const Array& arrayToOutput) {
	cout << "The Array received has " << arrayToOutput.getSize()
		 << " elements. The contents are:\n" << arrayToOutput << endl;
}

int main()
{

	PhoneNumber phone; // create object phone
	
	cout << "Enter phone number in the form (123) 456-7890:" << endl;
	// cin >> phone invokes operator>> by implicitly issuing
	// the global function call operator>>( cin, phone )
	//cin >> phone; // translated to operator>>( cin, phone );
		 
		
	cout << "The phone number entered was: ";
	// cout << phone invokes operator<< by implicitly issuing
	// the global function call operator<<( cout, phone )
	cout << phone << endl; // translated to operator<<( cout, phone );

	/*
	dynamic memory managment
	*/
	int arraySize = 0;
	cin >> arraySize;
	int* arr = new int[arraySize]; // alocate
	for (int i = 0; i < arraySize; i++)
		cin >> arr[i];
	delete arr; // deallocate

	/*
	Array exapmle overload all array in c++
	*/
	Array integers1(7); // seven-element Array
	Array integers2; // 10-element Array by default
	// print integers1 size and contents
	cout << "Size of Array integers1 is " << integers1.getSize() << "\nArray after initialization:\n" << integers1;
	// print integers2 size and contents
	cout << "\nSize of Array integers2 is " << integers2.getSize() << "\nArray after initialization:\n" << integers2;
	// input and print integers1 and integers2
	cout << "\nEnter 17 integers:" << endl;

	cin >> integers1 >> integers2;

	cout << "\nAfter input, the Arrays contain:\n" << "integers1:\n" << integers1 << "integers2:\n" << integers2;

	// use overloaded inequality (!=) operator
	cout << "\nEvaluating: integers1 != integers2" << endl;

	if (integers1 != integers2)
		cout << "integers1 and integers2 are not equal" << endl;

	// create Array integers3 using integers1 as an
	// initializer; print size and contents
	Array integers3(integers1); // invokes copy constructor

	cout << "\nSize of Array integers3 is " << integers3.getSize() << "\nArray after initialization:\n" << integers3;

	// use overloaded assignment (=) operator
	cout << "\nAssigning integers2 to integers1:" << endl;
	integers1 = integers2; // note target Array is smaller


	cout << "integers1:\n" << integers1 << "integers2:\n" << integers3;

	// use overloaded equality (==) operator
	cout << "\nEvaluating: integers1 == integers2" << endl;

	if (integers1 == integers2)
		cout << "integers1 and integers2 are equal" << endl;

	// use overloaded subscript operator to create rvalue
	cout << "\nintegers1[5] is " << integers1[5];

	// use overloaded subscript operator to create lvalue
	cout << "\n\nAssigning 1000 to integers1[5]" << endl;
	integers1[5] = 1000;
	cout << "integers1:\n" << integers1;

	// attempt to use out-of-range subscript
	cout << "\nAttempt to assign 1000 to integers1[15]" << endl;
	integers1[15] = 1000; // ERROR: out of range

	/*
	Date class
	overload x++, ++x, x+=1
	
	*/
	Date d1; // defaults to January 1, 1900
	Date d2(12, 27, 1992); // December 27, 1992
	Date d3(0, 99, 8045); // invalid date
	cout << "d1 is " << d1 << "\nd2 is " << d2 << "\nd3 is " << d3;
	cout << "\n\nd2 += 7 is " << (d2 += 7);
    d3.setDate(2, 28, 1992);
	cout << "\n\n d3 is " << d3;
	cout << "\n++d3 is " << ++d3 << " (leap year allows 29th)";
	Date d4(7, 13, 2002);
	cout << "\n\nTesting the prefix increment operator:\n"
		<< " d4 is " << d4 << endl;
	cout << "++d4 is " << ++d4 << endl;
	cout << " d4 is " << d4;
	cout << "\n\nTesting the postfix increment operator:\n"
		<< " d4 is " << d4 << endl;
	cout << "d4++ is " << d4++ << endl;
	cout << " d4 is " << d4 << endl;

	/*
	explicit and implict constructors and type conversions
	*/
	Array integers1(7); // 7-element array
	outputArray(integers1); // output Array integers1
	//outputArray(3); // convert 3 to an Array and output Array’s contents in case default constructor
					// if constructor is explicit it throw error


} // end main

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
