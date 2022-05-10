#pragma once
#include "Date.h"
#include "Fraction.h"
#include "Macro.h"
#include "Standard.h"
#include "Flags.h"

class Converter
{
public:
	static tuple<State, string> tryParse(string, regex);

public:
	static int parseInt(string str);
	static float parseFloat(string str);
	static Date parseDate(string str);
	static Fraction parseFraction(string str);

public:
	static string toString(Date);
	static string toString(Fraction);
};
