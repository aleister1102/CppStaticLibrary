#pragma once
#include "Standard.h"
#include "StringHelper.h"

class FileHelper
{
private:
	inline static std::shared_ptr<FileHelper> _instance = nullptr;
	static std::fstream _file;
	FileHelper() {}

public:
	static std::shared_ptr<FileHelper> Instance();

public:
	static void readFile(std::string);
	static void writeFile(std::string);
	static std::vector<std::vector<std::string>> readCSV(std::string);
	static std::vector<std::string> readTXT(std::string);
};