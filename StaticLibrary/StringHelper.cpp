#include "StringHelper.h"

/**
 * Given a string, it will return a vector of strings, where each string is a substring of the original
 * string delimited by the del string
 *
 * @param s The string to be parsed.
 * @param del The delimiter string.
 *
 * @return A vector of strings.
 */
vector<string> StringHelper::split(string s, string delimiter)
{
	vector<string> infos;

	size_t start = 0;
	size_t end = (int)s.find(delimiter);
	while (end != string::npos)
	{
		infos.push_back(s.substr(start, end - start));
		start = end + delimiter.size();
		end = s.find(delimiter, start);
	}
	infos.push_back(s.substr(start, end - start));

	return infos;
}

/**
 * It removes all leading and trailing characters of a given type, and then removes all instances of
 * that character that are next to each other
 *
 * @param line The string to be trimmed.
 * @param character The character to trim from the string.
 *
 * @return a string.
 */
string StringHelper::trim(string line, char character)
{
	string result = line;
	
	while (result.at(0) == character)
	{
		result.erase(0, 1);
	}

	while (result.at(result.length() - 1) == character)
	{
		result.erase(result.length() - 1, 1);
	}

	for (size_t i = 0; i < result.size(); i++)
	{
		if (result.at(i) == character)
		{
			if (result.at(i - 1) == character || result.at(i + 1) == character)
			{
				result.erase(i, 1);
				i -= 1;
			}
		}
	}

	return result;
}

/**
 * It takes a string and a regex pattern and returns the first match of the pattern in the string
 *
 * @param line The string to search in
 * @param pattern The pattern to search for.
 *
 * @return The first match of the pattern in the line, if found.
 * If not found, return empty string.
 */
string StringHelper::searchRegex(string line, string pattern)
{
	regex rgx(pattern);
	smatch match;
	regex_search(line, match, rgx);
	if (match.size() >= 1)
		return match[0];
	return "";
}

/**
 * It takes a string and returns a string with all the characters in lowercase
 *
 * @param str The string to convert to lowercase.
 *
 * @return A string
 */
string StringHelper::toLowerCase(string str)
{
	string builder;

	for (size_t i = 0; i < str.length(); i++)
	{
		builder += (char)tolower(str.at(i));
	}

	return builder;
}

/**
 * Converts a string to uppercase.
 *
 * @param str The string to convert to upper case.
 *
 * @return A string
 */
string StringHelper::toUpperCase(string str)
{
	string builder;

	for (size_t i = 0; i < str.length(); i++)
	{
		builder += (char)toupper(str.at(i));
	}

	return builder;
}