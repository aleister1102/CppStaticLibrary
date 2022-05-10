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

Date::Date(const Date &other)
{
	_day = other._day;
	_month = other._month;
	_year = other._year;
}

Date &Date::operator=(const Date &other)
{
	_day = other._day;
	_month = other._month;
	_year = other._year;
	return *this;
}

Date::~Date() {}

bool Date::isLeapYear() const
{
	return (((_year % 4 == 0) && (_year % 100 != 0)) || (_year % 400 == 0));
}

bool Date::isValid() const
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

int Date::daysInMonth() const
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

// ------------- Converter -------------

string DateConverter::convert(const Date &date)
{
	stringstream builder;

	if (date.isValid())
	{
		if (date.getDay() < 10 && date.getDay() > 0)
			builder << "0";
		builder << date.getDay() << "/";
		if (date.getMonth() < 10 && date.getMonth() > 0)
			builder << "0";
		builder << date.getMonth() << "/" << date.getYear();
	}
	else
	{
		builder << "Can not convert to string, date is invalid";
	}

	string result = builder.str();
	return result;
}

Date DateConverter::convertBack(const string str)
{
	Flags flags;
	string date;
	shared_ptr<Date> result = nullptr;

	tie(flags, date) = Converter::tryParse(str, regex(DATE));
	if (!flags.Successful())
	{
		cout << "Can not parse date!\n";
		cout << "Error code: " << flags.ErrorCode() << endl;
		cout << "Message: " << flags.Message() << endl;
	}
	else
	{
		auto tokens = StringHelper::split(date, "/");
		result = make_shared<Date>(Converter::parseInt(tokens[0]), Converter::parseInt(tokens[1]), Converter::parseInt(tokens[2]));
		if (!result->isValid())
			cout << "Invalid date!\n";
	}

	return *result;
}