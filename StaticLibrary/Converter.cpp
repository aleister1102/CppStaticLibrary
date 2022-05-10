#include "Converter.h"

// ------------- tryParse -------------

/**
 * It takes a string and a regex pattern, and returns a tuple containing a State object and a string.
 * The State object contains information about whether the regex pattern matched the string, and if
 * not, what the error was. The string contains the matched string
 *
 * @param str The string to be parsed
 * @param pattern The regular expression to use for parsing.
 *
 * @return A tuple of type tuple&lt;State, string&gt;
 */
tuple<State, string> Converter::tryParse(string str, regex pattern)
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

/**
 * It converts a date object to a string
 *
 * @param date The date to convert to a string
 *
 * @return A string
 */
string Converter::toString(Date date)
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

/**
 * This function converts a fraction to a string
 *
 * @param fraction The fraction to convert to a string.
 *
 * @return A string
 */
string Converter::toString(Fraction fraction)
{
	stringstream builder;
	if (fraction.isValid())
	{
		builder << fraction.Numerator() << "/" << fraction.Denominator();
	}
	else
	{
		builder << "Can not convert to string, fraction is invalid";
	}

	string result = builder.str();
	return result;
}

// ------------- parse -------------

/**
 * It takes a string, checks if it matches the regex pattern, and if it does, it returns the number as
 * an integer
 *
 * @param str The string to be parsed.
 *
 * @return A tuple of State and string.
 */
int Converter::parseInt(const string str)
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

/**
 * It takes a string, checks if it matches the regex pattern, and if it does, it returns the float
 * value of the string
 *
 * @param str The string to parse
 *
 * @return A tuple of State and string.
 */
float Converter::parseFloat(const string str)
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

/**
 * It takes a string, tries to parse it as a date, and returns a Date object
 *
 * @param str The string to parse
 *
 * @return A shared pointer to a Date object.
 */
Date Converter::parseDate(const string str)
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

/**
 * It takes a string, tries to parse it as a fraction, and returns a Fraction object
 *
 * @param str The string to be parsed.
 *
 * @return A fraction object.
 */
Fraction Converter::parseFraction(const string str)
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