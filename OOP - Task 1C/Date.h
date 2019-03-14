#pragma once

using namespace std;

class Date
{
public:
	//Constructors
	Date(const int&, const int&, const int&);
	Date(const Date&);

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