#include <Converter.h>
#include <Fraction.h>

int main()
{
	Date date1(-2, -1, 2002);
	Date date2(20, 2, 2002);

	std::cout << Converter::toString(date1) << std::endl;
	std::cout << Converter::toString(date2) << std::endl;

	Fraction f1(1, 0);
	std::cout << Converter::toString(f1) << std::endl;

	return 0;
}