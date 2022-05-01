#include "Date.h"

Date::Date()
{
	_day = 0;
	_month = 0;
	_year = 0;
}

Date::Date(int d, int m, int y)
{
	_day = d;
	_month = m;
	_year = y;
	if (!isValid())
		std::cout << "Invalid Date!\n";
}

Date::Date(const Date& other)
{
	_day = other._day;
	_month = other._month;
	_year = other._year;
}

Date Date::operator=(const Date& other)
{
	_day = other._day;
	_month = other._month;
	_year = other._year;
	return *this;
}

Date::~Date() {}

bool Date::isLeapYear()
{
	return (((_year % 4 == 0) && (_year % 100 != 0)) || (_year % 400 == 0));
}

bool Date::isValid()
{
	if (_year < 0)
	{
		return false;
	}

	if (_month < 1 || _month > 12)
	{
		return false;
	}

	if (_day < 1 || _day > this->daysInMonth())
	{
		return false;
	}

	return true;
}

int Date::daysInMonth()
{
	int days = 0;

	switch (_month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		days = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		days = 30;
		break;
	case 2:
		if (this->isLeapYear())
		{
			days = 29;
		}
		else
		{
			days = 28;
		}
		break;
	}

	return days;
}

// ------------- Operator -------------

bool Date::operator==(Date other)
{
	return (_day == other._day && _month == other._month && _year == other._year);
}