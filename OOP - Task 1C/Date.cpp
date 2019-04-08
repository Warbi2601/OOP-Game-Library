#include "Date.h"

using namespace std;

// add function for reading a date string and constructing an object

#pragma region Constructors

//Constructors
Date::Date(const int& d, const int& m, const int& y) //Don't need initialisation list as variables are changed in body
{
	month = checkMonthInBounds(m);
	day = checkDayInBounds(d);
	year = max(1, y);
}

Date::Date(const Date& date) : day(date.day), month(date.month), year(date.year)
{
	//Shouldn't need to recheck the max/min days/months
}

Date::Date(const string& str)
{
	string strYear = str.substr(0, 4);
	string strMonth = str.substr(5, 2);
	string strDay = str.substr(8, 2);

	int dayNum, monthNum, yearNum;

	istringstream dayStream(strDay);
	dayStream >> dayNum;

	istringstream monthStream(strMonth);
	monthStream >> monthNum;

	istringstream yearStream(strYear);
	yearStream >> yearNum;

	this->day = dayNum;
	this->month = monthNum;
	this->year = yearNum;
}

#pragma endregion

#pragma region Getters

//Getters
Date Date::getDate()
{
	return Date(this->day, this->month, this->year);
}

int Date::getDay() const
{
	return this->day;
}

int Date::getMonth() const
{
	return this->month;
}

int Date::getYear() const
{
	return this->year;
}

#pragma endregion

#pragma region Setters

//Setters
const void Date::setDate(const Date& date)
{
	this->month = checkMonthInBounds(date.month);
	this->day = checkDayInBounds(date.day);
	this->year = max(1, date.year);
}

const void Date::setDate(const int& d, const int& m, const int& y)
{
	this->month = checkMonthInBounds(m);
	this->day = checkDayInBounds(d);
	this->year = max(1, y);
}

const void Date::setDay(const int& d)
{
	this->day = checkDayInBounds(d);
}

const void Date::setMonth(const int& m)
{
	this->month = checkMonthInBounds(m);
}

const void Date::setYear(const int& y)
{
	this->year = y;
}

#pragma endregion

#pragma region Static

//Static
Date Date::CurrentDate()
{
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);
	int year = 1900 + ltm.tm_year;
	int month = 1 + ltm.tm_mon;
	int day = ltm.tm_mday;

	return Date(day, month, year);
}

#pragma endregion

#pragma region Utility

//Utility
const string Date::ToString(const Date& date) const
{
	stringstream ss;
	ss << setw(2) << std::setfill('0') << date.day << '/'
		<< setw(2) << std::setfill('0') << date.month << '/'
		<< setw(4) << std::setfill('0') << date.year;
	string s = ss.str();
	return s;
}

const int Date::checkMonthInBounds(const int& m) const
{
	int month;
	month = max(1, m);
	month = min(month, 12);
	return m;
}

//get rid of return by getting rid of const?
const int Date::checkDayInBounds(const int& d) const
{
	int day;
	int length[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	day = max(1, d);
	day = min(day, length[month]);
	return day;
}

const int Date::min(const int& a, const int& b) const
{
	if (a > b) return(b); else return (a);
}

const int Date::max(const int& a, const int& b) const
{
	if (a > b) return(a); else return (b);
}

#pragma endregion

#pragma region OverloadedOperators

//Overloaded Operators
ostream& operator<<(ostream& os, Date* datePointer)
{
	os << datePointer->ToString(*datePointer);
	return os;
}

bool operator<(const Date& lhs, const Date& rhs)
{
	if (lhs.getYear() < rhs.getYear())       return true;
	if (lhs.getYear() > rhs.getYear())       return false;
	if (lhs.getMonth() < rhs.getMonth())     return true;
	if (lhs.getMonth() > rhs.getMonth())     return false;
	if (lhs.getDay() < rhs.getDay())       return true;
	if (lhs.getDay() > rhs.getDay())       return false;

	return false;
}

#pragma endregion