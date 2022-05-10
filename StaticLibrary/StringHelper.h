#pragma once
#include "Standard.h"

class StringHelper
{
public:
	static vector<string> split(string, string delimiter = " ");
	static string trim(string, char character = ' ');
	static string searchRegex(string, string);
	static string toLowerCase(string);
	static string toUpperCase(string);
};