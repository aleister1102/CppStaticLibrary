#include "Fraction.h"

Fraction Fraction::lowestTerm() const
{
	int gcd = MathHelper::gcd(_num, _den);
	int num = _num / gcd;
	int den = _den / gcd;

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
}

Fraction::Fraction(int f)
{
	_num = f;
	_den = 1;
}