#pragma once
#include "Macro.h"
#include "Standard.h"
#include "Flags.h"

class Converter
{
public:
	static tuple<Flags, string> tryParse(string, regex);

public:
	static int parseInt(string str);
	static float parseFloat(string str);
};
