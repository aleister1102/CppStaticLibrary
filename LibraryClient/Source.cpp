#include <Converter.h>

int main()
{
	cout << Converter::toString(1.1) << endl;
	cout << Converter::parseInt("1") << endl;
	cout << Converter::parseFloat("1.1") << endl;
	Date date = Converter::parseDate("28/02/2002");
	cout << Converter::toString(date) << endl;
	Fraction fraction(1, 0);
	cout << Converter::toString(fraction) << endl;
	

	
	return 0;
}