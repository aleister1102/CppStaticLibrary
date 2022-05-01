#include "Converter.h"

// ------------- tryParse -------------

tuple<State, string> Converter::tryParse(const string& str, regex pattern)
{
	State flags;
	string matchStr;

	if (str.size() == 0)
	{
		flags.setSuccessful(false);
		flags.setErrorCode(2);
		flags.setMessage("Empty string");
	}
	else
	{
		smatch match;
		bool isMatched = regex_search(str, match, pattern);
		if (!isMatched)
		{
			flags.setSuccessful(false);
			flags.setErrorCode(1);
			flags.setMessage("Invalid format");
		}
		else
		{
			matchStr = match[0];
		}
	}

	auto result = make_tuple(flags, matchStr);
	return result;
}

// ------------- toString -------------

string Converter::toString(const Date& date)
{
	stringstream builder;

	if (date.getDay() < 10)
		builder << "0";
	builder << date.getDay() << "/";
	if (date.getMonth() < 10)
		builder << "0";
	builder << date.getMonth() << "/" << date.getYear();

	string result = builder.str();
	return result;
}

string Converter::toString(const Fraction& fraction)
{
	stringstream builder;

	builder << fraction.Numerator() << "/" << fraction.Denominator();

	string result = builder.str();
	return result;
}

// ------------- parse -------------

int Converter::parseInt(const string& str)
{
	State flags;
	string number;
	int result = 0;

	tie(flags, number) = tryParse(str, regex(NUMBERS));
	if (!flags.Successful())
	{
		cout << "Can not parse int!\n";
		cout << "Error code: " << flags.ErrorCode() << endl;
		cout << "Message: " << flags.Message() << endl;
	}
	else
	{
		result = stoi(number);
	}

	return result;
}

float Converter::parseFloat(const string& str)
{
	State flags;
	string number;
	float result = 0;

	tie(flags, number) = tryParse(str, regex(FLOAT));
	if (!flags.Successful())
	{
		cout << "Can not parse float!\n";
		cout << "Error code: " << flags.ErrorCode() << endl;
		cout << "Message: " << flags.Message() << endl;
	}
	else
	{
		result = stof(number);
	}

	return result;
}

Date Converter::parseDate(const string& str)
{
	State flags;
	string date;
	shared_ptr<Date> result = nullptr;

	tie(flags, date) = tryParse(str, regex(DATE));
	if (!flags.Successful())
	{
		cout << "Can not parse date!\n";
		cout << "Error code: " << flags.ErrorCode() << endl;
		cout << "Message: " << flags.Message() << endl;
	}
	else
	{
		auto tokens = StringHelper::split(date, "/");
		result = make_shared<Date>(parseInt(tokens[0]), parseInt(tokens[1]), parseInt(tokens[2]));
		if (!result->isValid())
			cout << "Invalid date!\n";
	}

	return *result;
}

Fraction Converter::parseFraction(const string& str)
{
	State flags;
	string fraction;
	shared_ptr<Fraction> result = nullptr;

	tie(flags, fraction) = tryParse(str, regex(FRACTION));
	if (!flags.Successful())
	{
		cout << "Can not parse fraction!\n";
		cout << "Error code: " << flags.ErrorCode() << endl;
		cout << "Message: " << flags.Message() << endl;
	}

	else
	{
		auto tokens = StringHelper::split(fraction, "/");
		result = make_shared<Fraction>(parseInt(tokens[0]), parseInt(tokens[1]));
	}

	return *result;
}