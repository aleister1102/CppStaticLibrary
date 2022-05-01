#pragma once
#include "Date.h"
#include "Fraction.h"
#include "Macro.h"
#include "Standard.h"
#include "State.h"

class Converter
{
public:
	static std::tuple<State, std::string> tryParse(std::string, std::regex);

public:
	static int parseInt(std::string str);
	static float parseFloat(std::string str);
	static Date parseDate(std::string str);
	static Fraction parseFraction(std::string str);

public:
	static std::string toString(Date);
	static std::string toString(Fraction);
};
