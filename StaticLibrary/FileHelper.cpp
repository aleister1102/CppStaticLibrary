#include "FileHelper.h"

FileHelper* FileHelper::Instance()
{
	if (_instance == nullptr)
	{
		_instance = new FileHelper();
	}

	return _instance;
}

void FileHelper::readFile(string fileName)
{
	_file.open(fileName, ios::out | ios::trunc);

	if (!_file)
	{
		cout << "File is not found!\n";
		_file.close();
	}
}

void FileHelper::writeFile(string fileName)
{
	_file.open(fileName, ios::out | ios::trunc);

	if (!_file)
	{
		cout << "File is not found!\n";
		_file.close();
	}
}

/**
 * Reads a CSV _file and returns a vector of vectors of strings
 *
 * @param _fileName the name of the _file to be read
 *
 * @return A vector of vectors of strings.
 */
vector<vector<string>> FileHelper::readCSV(string fileName)
{
	vector<vector<string>> parsedStrings;

	readFile(fileName);

	string line;
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
 * Reads a text _file and returns a vector of strings
 *
 * @param _fileName the name of the _file to be read.
 *
 * @return A vector of strings.
 */
vector<string> FileHelper::readTXT(string fileName)
{
	vector<string> strings;

	readFile(fileName);

	string line;
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