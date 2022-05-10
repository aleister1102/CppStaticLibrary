#include "Fraction.h"

// ------------- DTO -------------

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
		cout << "Invalid fraction!\n";
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

Fraction& Fraction::operator=(const Fraction& other)
{
	_num = other._num;
	_den = other._den;
	return *this;
}

Fraction::~Fraction() {}

bool Fraction::isValid() const
{
	return !(_den == 0);
}

/**
 * The function converts the fraction to its lowest term by dividing the numerator and denominator by
 * their greatest common divisor
 *
 * @return A Fraction object.
 */
Fraction Fraction::toLowestTerm() const
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

// ------------- Operator -------------

Fraction Fraction::operator+(Fraction other)
{
	int num = Numerator() * other.Denominator() + other.Numerator() * Denominator();
	int den = Denominator() * other.Denominator();
	Fraction result(num, den);
	return result.toLowestTerm();
}

Fraction Fraction::operator-(Fraction other)
{
	int num = Numerator() * other.Denominator() - other.Numerator() * Denominator();
	int den = Denominator() * other.Denominator();
	Fraction result(num, den);
	return result.toLowestTerm();
}

Fraction Fraction::operator*(Fraction other)
{
	int num = Numerator() * other.Numerator();
	int den = Denominator() * other.Denominator();
	Fraction result(num, den);
	return result.toLowestTerm();
}

Fraction Fraction::operator/(Fraction other)
{
	int num = Numerator() * other.Denominator();
	int den = Denominator() * other.Numerator();
	Fraction result(num, den);
	return result.toLowestTerm();
}

// ------------- Converter -------------

string FractionConverter::convert(const Fraction& fraction, void* args)
{
	stringstream builder;
	if (fraction.isValid())
	{
		builder << fraction.Numerator() << "/" << fraction.Denominator();
	}
	else
	{
		builder << "Can not convert to string, fraction is invalid";
	}

	string result = builder.str();
	return result;
}

Fraction FractionConverter::convertBack(const string str)
{
	Flags flags;
	string fraction;
	shared_ptr<Fraction> result = nullptr;

	tie(flags, fraction) = Converter::tryParse(str, regex(FRACTION));
	if (!flags.Successful())
	{
		cout << "Can not parse fraction!\n";
		cout << "Error code: " << flags.ErrorCode() << endl;
		cout << "Message: " << flags.Message() << endl;
	}

	else
	{
		auto tokens = StringHelper::split(fraction, "/");
		result = make_shared<Fraction>(Converter::parseInt(tokens[0]), Converter::parseInt(tokens[1]));
	}

	return *result;
}

/**
 * It converts a fraction to its lowest term and returns the result as a string
 *
 * @param f The fraction to convert.
 * @param args This is a pointer to a void pointer. This is used to pass in any arguments that the
 * converter may need.
 *
 * @return A string
 */
string FractionToLowestTermConverter::convert(const Fraction& fraction, void* args)
{
	auto lowest = fraction.toLowestTerm();

	stringstream builder;

	builder << lowest.Numerator() << "/" << lowest.Denominator();

	string result = builder.str();
	return result;
}

/**
 * If the numerator is greater than or equal to the denominator, then we have a whole number, so we
 * divide the numerator by the denominator to get the whole number, and then we get the remainder of
 * the numerator divided by the denominator to get the numerator of the fractional part.
 *
 * If the numerator is less than the denominator, then we have a fractional number, so we just output
 * the numerator and denominator.
 *
 * Here's the output of the above function:
 *
 * @param f The fraction to convert
 * @param args This is a pointer to a void pointer. This is used to pass in any arguments that the
 * converter may need.
 *
 * @return A string
 */
string FractionToMixedFractionConverter::convert(const Fraction& fraction, void* args)
{
	auto lowest = fraction.toLowestTerm();
	stringstream builder;

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

	string result = builder.str();
	return result;
}

/**
 * The function converts a fraction to a decimal string with a specified number of decimal places
 *
 * @param f The fraction to convert.
 * @param args This is a pointer to a void pointer. This is a pointer to a pointer to a void. This is a
 * pointer to a pointer to a memory location that can hold any type of data.
 *
 * @return A string
 */
string FractionToDecimalConverter::convert(const Fraction& fraction, void* args)
{
	float value = ((float)fraction.Numerator()) / fraction.Denominator();
	int* precision = (int*)args;
	int number = *precision;

	stringstream builder;

	builder << setprecision(number) << value;

	string result = builder.str();
	return result;
}

// ------------- Converter Factory -------------

/**
 * It returns a pointer to a new instance of a class that implements the FractionConverter interface
 *
 * @param type The type of converter to create.
 *
 * @return A pointer to a FractionConverter object.
 */
FractionConverter* FractionConverterFactory::createConverter(int type)
{
	switch (type)
	{
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