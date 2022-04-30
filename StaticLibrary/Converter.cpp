#include "Converter.h"

// ------------- toString -------------

string Converter::toString(const float& number)
{
	stringstream builder;
	builder << number;
	return builder.str();
}

// ------------- tryParse -------------

tuple<State, string> Converter::tryParse(const string& str)
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
		regex pattern();
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

int Converter::parseInt(const string& str)
{
	State flags;
	int number;

	tie(flags, number) = tryParseInt(str);
	if (!flags.Successful())
	{
		cout << "Error code: " << flags.ErrorCode() << endl;
		cout << "Message: " << flags.Message() << endl;
	}
	return number;
}