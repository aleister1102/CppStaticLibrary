#include "StringHelper.h"

/**
 * Given a std::string, it will return a std::vector of std::strings, where each std::string is a substd::string of the original
 * std::string delimited by the del std::string
 *
 * @param s The std::string to be parsed.
 * @param del The delimiter std::string.
 *
 * @return A std::vector of std::strings.
 */
std::vector<std::string> StringHelper::split(std::string s, std::string delimiter)
{
	std::vector<std::string> infos;

	size_t start = 0;
	size_t end = (int)s.find(delimiter);
	while (end != std::string::npos)
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
 * @param line The std::string to be trimmed.
 * @param character The character to trim from the std::string.
 *
 * @return a std::string.
 */
std::string StringHelper::trim(std::string line, char character)
{
	std::string result = line;
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
 * It takes a std::string and a regex pattern and returns the first match of the pattern in the std::string
 *
 * @param line The std::string to search in
 * @param pattern The pattern to search for.
 *
 * @return The first match of the pattern in the line, if found.
 * If not found, return empty std::string.
 */
std::string StringHelper::searchRegex(std::string line, std::string pattern)
{
	std::regex rgx(pattern);
	std::smatch match;
	std::regex_search(line, match, rgx);
	if (match.size() >= 1)
		return match[0];
	return "";
}

std::string StringHelper::toLowerCase(std::string str)
{
	std::string builder;

	for (size_t i = 0; i < str.length(); i++)
	{
		builder += (char)tolower(str.at(i));
	}

	return builder;
}

std::string StringHelper::toUpperCase(std::string str)
{
	std::string builder;

	for (size_t i = 0; i < str.length(); i++)
	{
		builder += (char)toupper(str.at(i));
	}

	return builder;
}