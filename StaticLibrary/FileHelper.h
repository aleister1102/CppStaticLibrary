#pragma once
#include "Standard.h"
#include "StringHelper.h"

class FileHelper
{
private:
	inline static FileHelper* _instance = nullptr;
	static fstream _file;
	FileHelper() {}
public:
	static FileHelper* Instance();

public:
	static void readFile(string);
	static void writeFile(string);
	static vector<vector<string>> readCSV(string);
	static vector<string> readTXT(string);
};