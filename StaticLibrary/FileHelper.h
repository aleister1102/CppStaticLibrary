#pragma once
#include "Standard.h"
#include "StringHelper.h"

class FileHelper
{
private:
	inline static shared_ptr<FileHelper> _instance = nullptr;
	FileHelper() {}

public:
	static shared_ptr<FileHelper> Instance();

public:
	static fstream readFile(string);
	static fstream writeFile(string);
	static vector<vector<string>> readCSV(string);
	static vector<string> readTXT(string);
};