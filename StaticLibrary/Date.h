#pragma once
#include "Standard.h"
#include "StringHelper.h"

class Date
{
private:
	int _day;
	int _month;
	int _year;

public:
	int getDay() const { return _day; }
	int getMonth() const { return _month; }
	int getYear() const { return _year; }
	void setDay(int value) { _day = value; }
	void setMonth(int value) { _month = value; }
	void setYear(int value) { _year = value; }

public:
	Date();
	Date(int d, int m, int y);
	bool operator==(const Date& other);

public:
	bool isLeapYear();
	bool isValid();
	int daysInMonth();
};