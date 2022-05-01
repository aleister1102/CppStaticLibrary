#include <Converter.h>
#include <Fraction.h>

int main()
{
	Fraction f1(1, 2);
	Fraction f2(1, 3);
	Fraction f3 = f1 + f2;
	cout << Converter::toString(f3) << endl;
	return 0;
}