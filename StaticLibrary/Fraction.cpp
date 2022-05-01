#include "Fraction.h"

// ------------- DTO -------------

Fraction Fraction::lowestTerm() const
{
	int gcd = MathHelper::gcd(_num, _den);
	int num = _num / gcd;
	int den = _den / gcd;

	if (den < 0 && num < 0)
	{
		num *= -1;
		den *= -1;
	}
	else if (den < 0 && num > 0)
	{
		den *= -1;
	}

	Fraction result(num, den);
	return result;
}

Fraction::Fraction()
{
	_num = 0;
	_den = 1;
}

Fraction::Fraction(int x, int y)
{
	_num = x;
	_den = y;

	if (!isValid())
		std::cout << "Invalid fraction!\n";
}

Fraction::Fraction(int f)
{
	_num = f;
	_den = 1;
}

Fraction::Fraction(const Fraction& other)
{
	_num = other._num;
	_den = other._den;
}

Fraction Fraction::operator=(const Fraction& other)
{
	_num = other._num;
	_den = other._den;
	return *this;
}

Fraction::~Fraction() {}

bool Fraction::isValid()
{
	return !(_den == 0);
}

// ------------- Operator -------------

Fraction Fraction::operator+(Fraction other)
{
	int num = Numerator() * other.Denominator() + other.Numerator() * Denominator();
	int den = Denominator() * other.Denominator();
	Fraction result(num, den);
	return result.lowestTerm();
}

Fraction Fraction::operator-(Fraction other)
{
	int num = Numerator() * other.Denominator() - other.Numerator() * Denominator();
	int den = Denominator() * other.Denominator();
	Fraction result(num, den);
	return result.lowestTerm();
}

Fraction Fraction::operator*(Fraction other)
{
	int num = Numerator() * other.Numerator();
	int den = Denominator() * other.Denominator();
	Fraction result(num, den);
	return result.lowestTerm();
}

Fraction Fraction::operator/(Fraction other)
{
	int num = Numerator() * other.Denominator();
	int den = Denominator() * other.Numerator();
	Fraction result(num, den);
	return result.lowestTerm();
}

// ------------- Converter -------------

std::string FractionToLowestTermConverter::convert(const Fraction& f, void* args)
{
	Fraction lowest = f.lowestTerm();

	std::stringstream builder;

	builder << lowest.Numerator() << "/" << lowest.Denominator();

	std::string result = builder.str();
	return result;
}

std::string FractionToMixedFractionConverter::convert(const Fraction& f, void* args)
{
	auto lowest = f.lowestTerm();
	std::stringstream builder;

	if (lowest.Numerator() >= lowest.Denominator())
	{
		int fullNumber = lowest.Numerator() / lowest.Denominator();
		builder << fullNumber << " ";

		int num = lowest.Numerator() % lowest.Denominator();
		builder << num << "/";
	}
	else
	{
		builder << lowest.Numerator() << "/";
	}

	builder << lowest.Denominator();

	std::string result = builder.str();
	return result;
}

std::string FractionToDecimalConverter::convert(const Fraction& f, void* args)
{
	float value = ((float)f.Numerator()) / f.Denominator();
	int* precision = (int*)args;
	int number = *precision;

	std::stringstream builder;

	builder << std::setprecision(number) << value;

	std::string result = builder.str();
	return result;
}

// ------------- Converter Factory -------------

FractionConverter* FractionConverterFactory::createConverter(int type)
{
	switch (type) {
	case FractionConverterType::LOWEST_TERM:
		return new FractionToLowestTermConverter();
	case FractionConverterType::MIXED:
		return new FractionToMixedFractionConverter();
	case FractionConverterType::DECIMAL:
		return new FractionToDecimalConverter();
	default:
		return new FractionToLowestTermConverter();
	}
}