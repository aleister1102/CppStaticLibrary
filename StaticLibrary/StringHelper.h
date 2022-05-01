#pragma once
#include "Standard.h"

class StringHelper
{
public:
	static std::vector<std::string> split(std::string, std::string delimiter = " ");
	static std::string trim(std::string, char character = ' ');
	static std::string searchRegex(std::string, std::string);
	static std::string toLowerCase(std::string);
	static std::string toUpperCase(std::string);
};