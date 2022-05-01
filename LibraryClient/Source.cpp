#include <Converter.h>
#include <Fraction.h>
using namespace std;

int main()
{
	Fraction f1(9, 8);
	FractionConverter *converter = FractionConverterFactory::createConverter(FractionConverterType::MIXED);

	cout << converter->convert(f1) << endl;

	return 0;
}