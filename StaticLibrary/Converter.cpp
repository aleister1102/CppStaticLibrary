#include "Converter.h"

// ------------- tryParse -------------

/**
 * It takes a string and a regex pattern, and returns a tuple containing a Flags object and a string.
 * The Flags object contains information about whether the regex pattern matched the string, and if
 * not, what the error was. The string contains the matched string
 *
 * @param str The string to be parsed
 * @param pattern The regular expression to use for parsing.
 *
 * @return A tuple of type tuple&lt;Flags, string&gt;
 */
tuple<Flags, string> Converter::tryParse(string str, regex pattern)
{
	Flags flags;
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

// ------------- parse -------------

/**
 * It takes a string, checks if it matches the regex pattern, and if it does, it returns the number as
 * an integer
 *
 * @param str The string to be parsed.
 *
 * @return A tuple of Flags and string.
 */
int Converter::parseInt(const string str)
{
	Flags flags;
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
 * @return A tuple of Flags and string.
 */
float Converter::parseFloat(const string str)
{
	Flags flags;
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