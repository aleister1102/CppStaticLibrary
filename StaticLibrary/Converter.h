#pragma once
#include "Macro.h"
#include "State.h"
#include "Standard.h"
#include "Fraction.h"
#include "Date.h"

class Converter
{
public:
	static string toString(const float&);
	static string toString(const Date&);
	static string toString(const Fraction&);
	static tuple<State, string> tryParse(const string&, regex);
	static int parseInt(const string& str);
	static float parseFloat(const string& str);
	static Date parseDate(const string& str);
	static Fraction parseFraction(const string& str);
};


