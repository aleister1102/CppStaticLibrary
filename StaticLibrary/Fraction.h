#pragma once
#include "MathHelper.h"
#include "Standard.h"
#include "Flags.h"

class FractionConverterType
{
public:
	inline static const int LOWEST_TERM = 1;
	inline static const int  MIXED = 2;
	inline static const int  DECIMAL = 3;
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
	Fraction& operator=(const Fraction&);
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