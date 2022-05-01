#include <Converter.h>
#include <Fraction.h>
#include <RandomGenerator.h>
#include <DynamicArray.h>

using namespace std;

int main()
{
#if 1

	Fraction f1(9, 8);
	FractionConverter* converter = FractionConverterFactory::createConverter(FractionConverterType::MIXED);
	cout << converter->convert(f1) << endl;

	Date date(11, 02, 2002);
	cout << Converter::toString(date) << endl;

	RandomGenerator* rng = RandomGenerator::Instance();
	cout << rng->next() << endl;

	DynamicArray<int> intArray;
	for (int i = 0; i < 10; i++)
	{
		intArray.push_back(rng->next());
	}

	for (int i = 0; i < intArray.size(); i++)
	{
		cout << intArray[i] << " ";
	}

#endif
	return 0;
}