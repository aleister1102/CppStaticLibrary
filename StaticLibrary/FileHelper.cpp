#include "FileHelper.h"

FileHelper* FileHelper::Instance()
{
	if (_instance == nullptr)
	{
		_instance = new FileHelper();
	}

	return _instance;
}

void FileHelper::readFile(std::string fileName)
{
	_file.open(fileName, std::ios::out | std::ios::trunc);

	if (!_file)
	{
		std::cout << "File is not found!\n";
		_file.close();
	}
}

void FileHelper::writeFile(std::string fileName)
{
	_file.open(fileName, std::ios::out | std::ios::trunc);

	if (!_file)
	{
		std::cout << "File is not found!\n";
		_file.close();
	}
}

/**
 * It reads a CSV file and returns a vector of vectors of strings
 *
 * @param fileName The name of the file to read.
 *
 * @return A vector of vectors of strings.
 */
std::vector<std::vector<std::string>> FileHelper::readCSV(std::string fileName)
{
	std::vector<std::vector<std::string>> parsedStrings;

	readFile(fileName);

	std::string line;
	getline(_file, line);

	while (!_file.eof())
	{
		getline(_file, line);
		if (line == "")
			continue;
		auto parsedString = StringHelper::split(line, ",");
		parsedStrings.push_back(parsedString);
	}

	_file.close();
	return parsedStrings;
}

/**
 * It reads a text file and returns a vector of strings
 *
 * @param fileName The name of the file to be read.
 *
 * @return A std::vector of std::strings.
 */
std::vector<std::string> FileHelper::readTXT(std::string fileName)
{
	std::vector<std::string> strings;

	readFile(fileName);

	std::string line;
	while (!_file.eof())
	{
		getline(_file, line);
		if (line == "")
			continue;
		strings.push_back(line);
	}

	_file.close();
	return strings;
}