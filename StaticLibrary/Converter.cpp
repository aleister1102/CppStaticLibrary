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
 * @return A tuple of type tuple&lt;State, std::string&gt;
 */
std::tuple<State, std::string> Converter::tryParse(std::string str, std::regex pattern)
{
	State flags;
	std::string matchStr;

	if (str.size() == 0)
	{
		flags.setSuccessful(false);
		flags.setErrorCode(2);
		flags.setMessage("Empty std::string");
	}
	else
	{
		std::smatch match;
		bool isMatched = std::regex_search(str, match, pattern);
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
std::string Converter::toString(Date date)
{
	std::stringstream builder;

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

	std::string result = builder.str();
	return result;
}

/**
 * This function converts a fraction to a string
 *
 * @param fraction The fraction to convert to a string.
 *
 * @return A string
 */
std::string Converter::toString(Fraction fraction)
{
	std::stringstream builder;
	if (fraction.isValid())
	{
		builder << fraction.Numerator() << "/" << fraction.Denominator();
	}
	else
	{
		builder << "Can not convert to string, fraction is invalid";
	}

	std::string result = builder.str();
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
int Converter::parseInt(const std::string str)
{
	State flags;
	std::string number;
	int result = 0;

	tie(flags, number) = tryParse(str, std::regex(NUMBERS));
	if (!flags.Successful())
	{
		std::cout << "Can not parse int!\n";
		std::cout << "Error code: " << flags.ErrorCode() << std::endl;
		std::cout << "Message: " << flags.Message() << std::endl;
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
float Converter::parseFloat(const std::string str)
{
	State flags;
	std::string number;
	float result = 0;

	tie(flags, number) = tryParse(str, std::regex(FLOAT));
	if (!flags.Successful())
	{
		std::cout << "Can not parse float!\n";
		std::cout << "Error code: " << flags.ErrorCode() << std::endl;
		std::cout << "Message: " << flags.Message() << std::endl;
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
Date Converter::parseDate(const std::string str)
{
	State flags;
	std::string date;
	std::shared_ptr<Date> result = nullptr;

	tie(flags, date) = tryParse(str, std::regex(DATE));
	if (!flags.Successful())
	{
		std::cout << "Can not parse date!\n";
		std::cout << "Error code: " << flags.ErrorCode() << std::endl;
		std::cout << "Message: " << flags.Message() << std::endl;
	}
	else
	{
		auto tokens = StringHelper::split(date, "/");
		result = std::make_shared<Date>(parseInt(tokens[0]), parseInt(tokens[1]), parseInt(tokens[2]));
		if (!result->isValid())
			std::cout << "Invalid date!\n";
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
Fraction Converter::parseFraction(const std::string str)
{
	State flags;
	std::string fraction;
	std::shared_ptr<Fraction> result = nullptr;

	tie(flags, fraction) = tryParse(str, std::regex(FRACTION));
	if (!flags.Successful())
	{
		std::cout << "Can not parse fraction!\n";
		std::cout << "Error code: " << flags.ErrorCode() << std::endl;
		std::cout << "Message: " << flags.Message() << std::endl;
	}

	else
	{
		auto tokens = StringHelper::split(fraction, "/");
		result = std::make_shared<Fraction>(parseInt(tokens[0]), parseInt(tokens[1]));
	}

	return *result;
}