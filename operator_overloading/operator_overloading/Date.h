#pragma once
#include <iostream>
using namespace std;

class Date
{
	friend ostream& operator << (ostream&, const Date&);
public:
	 Date(int m = 1, int d = 1, int y = 1900); // default constructor
	 void setDate(int, int, int); // set month, day, year
	 static bool leapYear(int); // is date in a leap year?
	 bool endOfMonth(int) const; // is date at the end of month?
	 Date& operator++();
	 Date operator++(int);
	 const Date& operator+=(int);
private:
	 int month;
	 int day;
	 int year;
	 static const int days[]; // array of days per month
	 void helpIncrement(); // utility function for incrementing date
};

