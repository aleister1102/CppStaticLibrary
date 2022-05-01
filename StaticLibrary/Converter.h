#pragma once
#include "Macro.h"
#include "State.h"
#include "Standard.h"
#include "Fraction.h"
#include "Date.h"

class Converter
{
public:
	static tuple<State, string> tryParse(const string&, regex);
public:
	static int parseInt(const string& str);
	static float parseFloat(const string& str);
	static Date parseDate(const string& str);
	static Fraction parseFraction(const string& str);
public:
	static string toString(const Fraction&);
	static string toString(const Date&);
};
