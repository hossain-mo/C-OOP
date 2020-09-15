#include "Array.h"
#include <iostream>
#include <iomanip>
#include <cstdlib> // exit function prototype
#include "Array.h" // Array class definition
using namespace std;


// default constructor for class Array (default size 10)
Array::Array(int arraySize) {
	size = (arraySize > 0 ? arraySize : 10); // validate arraySize
	ptr = new int[size]; // create space for pointer-based array
	for (int i = 0; i < size; i++)
		ptr[i] = 0; // set pointer-
}
Array::Array(const Array& arrayToCopy) : size(arrayToCopy.size){
	 ptr = new int[size]; // create space for pointer-based array
	 for (int i = 0; i < size; i++)
		 ptr[i] = arrayToCopy.ptr[i]; // copy into object
} // end Array copy constructor

 // destructor for class Array
 Array::~Array(){
	 delete[] ptr; // release pointer-based array space
} // end destructor

 // return number of elements of Array
 int Array::getSize() const{
	 return size; // number of elements in Array
 } // end function getSize

const Array& Array::operator=(const Array& right) {
	if (this != &right) {
		if (this->size != right.size) {
			delete[] ptr;
			this->size = right.size;
			ptr = new int[this->size];
		}
		for (int i = 0; i < size; i++)
			this->ptr[i] = right.ptr[i];
	}
	return *this;
}
bool Array::operator==(const Array& right) const {
	if (this->size != right.size)
		return false;
	for (int i = 0; i < size; i++) {
		if (this->ptr[i] != right.ptr[i])
			return false;
	}
	return true;
}
int& Array::operator[](int subscript) {
	// check for subscript out-of-range error
	 if (subscript < 0 || subscript >= size){
		 cerr << "\nError: Subscript " << subscript
			 << " out of range" << endl;
		 exit(1); // terminate program; subscript out of range
	} // end if
	
	 return ptr[subscript]; // reference return
}
int Array::operator[](int subscript) const {
	// check for subscript out-of-range error
	if (subscript < 0 || subscript >= size) {
		cerr << "\nError: Subscript " << subscript
			<< " out of range" << endl;
		exit(1); // terminate program; subscript out of range
	} // end if

	return ptr[subscript]; // reference return
}

 // overloaded input operator for class Array;
 // inputs values for entire Array
 istream & operator>>(istream & input, Array & a){
	 for (int i = 0; i < a.size; i++)
		 input >> a.ptr[i];
	
		 return input; // enables cin >> x >> y;
} // end function

 // overloaded output operator for class Array
 ostream & operator<<(ostream & output, const Array & a){
	 int i;
	// output private ptr-based array
	for (i = 0; i < a.size; i++){
	output << setw(12) << a.ptr[i];
		
		if ((i + 1) % 4 == 0) // 4 numbers per row of output
		output << endl;
	} // end for
	
	if (i % 4 != 0) // end last line of output
	output << endl;
	
	return output; // enables cout << x << y;
} // end function operator<<