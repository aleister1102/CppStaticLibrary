#pragma once
#include "Standard.h"

class StringHelper
{
public:
	static vector<string> split(string, string delimiter = " ");
	static string trim(string, char character = ' ');
	static string searchRegex(string, string, size_t index = 1);
	static string toLowerCase(string);
	static string toUpperCase(string);
};