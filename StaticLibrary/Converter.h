#pragma once
#include "Macro.h"
#include "State.h"
#include "Standard.h"
#include "Fraction.h"

class Converter
{
public:
	static string toString(const float&);
	static tuple<State, string> tryParse(const string&);
	static int parseInt(const string& str);
};
