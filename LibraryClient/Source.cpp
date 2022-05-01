#include <Converter.h>
#include <Fraction.h>
#include <Randomizer.h>
using namespace std;

int main()
{
	Fraction f1(9, 8);
	FractionConverter* converter = FractionConverterFactory::createConverter(FractionConverterType::MIXED);

	cout << converter->convert(f1) << endl;

	RandomGenerator* rng = RandomGenerator::Instance();
	cout << rng->next() << endl;
	return 0;
}