#pragma once
#include "MathHelper.h"
#include "Standard.h"
#include "State.h"

enum FractionConverterType
{
	LOWEST_TERM = 1,
	MIXED,
	DECIMAL
};

class Fraction
{
private:
	int _num;
	int _den;

public:
	int Numerator() const { return _num; }
	int Denominator() const { return _den; }
	void setNumerator(int value) { _num = value; }
	void setDenominator(int value) { _den = value; }
	Fraction toLowestTerm() const;

public:
	Fraction();
	Fraction(int, int);
	Fraction(int);
	Fraction operator=(const Fraction&);
	Fraction(const Fraction&);
	~Fraction();

public:
	bool isValid();

public:
	Fraction operator+(Fraction);
	Fraction operator-(Fraction);
	Fraction operator*(Fraction);
	Fraction operator/(Fraction);
};

class FractionConverter
{
public:
	virtual std::string convert(const Fraction& f, void* args = NULL) = 0;
	virtual Fraction convertBack(const std::string) = 0;
};

class FractionToLowestTermConverter : public FractionConverter
{
public:
	std::string convert(const Fraction& f, void* args = NULL);
	Fraction convertBack(const std::string)
	{
		// TODO
		return Fraction();
	}
};

class FractionToMixedFractionConverter : public FractionConverter
{
public:
	std::string convert(const Fraction& f, void* args = NULL);
	Fraction convertBack(const std::string)
	{
		// TODO
		return Fraction();
	}
};

class FractionToDecimalConverter : public FractionConverter
{
public:
	std::string convert(const Fraction&, void* args = NULL);
	Fraction convertBack(const std::string)
	{
		// TODO
		return Fraction();
	}
};

class FractionConverterFactory
{
public:
	static FractionConverter* createConverter(int type);
};