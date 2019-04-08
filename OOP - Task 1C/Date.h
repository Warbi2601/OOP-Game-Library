#pragma once

#include <iostream>
#include <time.h>
#include <sstream>
#include <iomanip>
#include <conio.h>
#include <ctime>
#include <assert.h>
#include <vector>

using namespace std;

class Date
{
public:
	//Constructors
	Date(const int&, const int&, const int&);
	Date(const Date&);
	Date(const string&);



	//Destructor not needed because no heap memory
	
	//Getters
	Date getDate();
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	
	//Setters
	const void setDay(const int&);
	const void setMonth(const int&);
	const void setYear(const int&);
	const void setDate(const Date&);
	const void setDate(const int&, const int&, const int&);

	//Utility
	const string ToString(const Date&) const;
	
	//Static
	static Date CurrentDate();
private:
	//Variables
	int day;
	int month;
	int year;

	//Utility Functions
	const int checkMonthInBounds(const int&) const;
	const int checkDayInBounds(const int&) const;
	const int min(const int&, const int&) const;
	const int max(const int&, const int&) const;
};
	
//Overloaded Operators
ostream& operator<<(ostream& os, Date* datePointer);

// For library sorting
bool operator<(const Date& lhs, const Date& rhs);