#include "FileHelper.h"

shared_ptr<FileHelper> FileHelper::Instance()
{
	if (_instance == nullptr)
	{
		_instance = shared_ptr<FileHelper>(new FileHelper());
	}

	return _instance;
}

fstream FileHelper::readFile(string fileName)
{
	fstream input;
	input.open(fileName, ios::in);

	if (!input)
	{
		cout << "File is not found!\n";
		input.close();
	}

	return input;
}

fstream FileHelper::writeFile(string fileName)
{
	fstream output;
	output.open(fileName, ios::out | ios::trunc);

	if (!output)
	{
		cout << "File is not found!\n";
		output.close();
	}

	return output;
}

/**
 * It reads a CSV file and returns a vector of vectors of strings
 *
 * @param fileName The name of the file to read.
 *
 * @return A vector of vectors of strings.
 */
vector<vector<string>> FileHelper::readCSV(string fileName)
{
	vector<vector<string>> parsedStrings;

	fstream input = readFile(fileName);
	if (!input) return parsedStrings;

	string line;
	getline(input, line);

	while (!input.eof())
	{
		getline(input, line);
		if (line == "")
			continue;
		auto parsedString = StringHelper::split(line, ",");
		parsedStrings.push_back(parsedString);
	}

	input.close();
	return parsedStrings;
}

/**
 * It reads a text file and returns a vector of strings
 *
 * @param fileName The name of the file to be read.
 *
 * @return A vector of strings.
 */
vector<string> FileHelper::readTXT(string fileName)
{
	vector<string> strings;

	fstream input = readFile(fileName);
	if (!input) return strings;

	string line;
	while (!input.eof())
	{
		getline(input, line);
		if (line == "")
			continue;
		strings.push_back(line);
	}

	input.close();
	return strings;
}