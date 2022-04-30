#pragma once
#include "Standard.h"
#include "Fraction.h"

class FractionToLowestTermConverter
{
public:
	string convert(const Fraction& f, void* args);
	Fraction convertBack(const string); // TODO
};

class FractionToMixedFractionConverter
{
public:
	string convert(const Fraction& f, void* args = NULL);
	Fraction convertBack(const string); // TODO
};

class FractionToDecimalConverter
{
public:
	string convert(const Fraction&, void* args = NULL);
	Fraction convertBack(const string); // TODO
};
