#pragma once
#include "Standard.h"
#include "MathHelper.h"

class Fraction {
private:
	int _num;
	int _den;
public:
	int Numerator() const { return _num; }
	int Denominator() const { return _den; }
	void setNumerator(int value) { _num = value; }
	void setDenominator(int value) { _den = value; }
	Fraction lowestTerm() const;
public:
	Fraction();
	Fraction(int, int);
	Fraction(int);
};
