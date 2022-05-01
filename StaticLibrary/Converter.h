#pragma once
#include "Macro.h"
#include "State.h"
#include "Standard.h"
#include "Fraction.h"
#include "Date.h"

class Converter
{
public:
	static std::tuple<State, std::string> tryParse(const std::string&, std::regex);
public:
	static int parseInt(std::string str);
	static float parseFloat(std::string str);
	static Date parseDate(std::string str);
	static Fraction parseFraction(std::string str);
public:
	static std::string toString(Date);
	static std::string toString(Fraction);
};
