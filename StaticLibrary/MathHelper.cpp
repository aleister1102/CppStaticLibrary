#include "MathHelper.h"

int MathHelper::gcd(int a, int b)
{
	while (a * b != 0)
	{
		if (a > b)
		{
			a = a - b;
		}
		else
		{
			b = b - a;
		}
	}
	return a;
}

int MathHelper::lcm(int a, int b)
{
	return a * b / gcd(a, b);
}