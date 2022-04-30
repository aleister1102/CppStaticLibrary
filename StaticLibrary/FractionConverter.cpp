#include "FractionConverter.h"

string FractionToLowestTermConverter::convert(const Fraction& f, void* args)
{
    Fraction lowest = f.lowestTerm();

    stringstream builder;

    builder << lowest.Numerator() << "/" << lowest.Denominator();

    string result = builder.str();
    return result;
}

string FractionToMixedFractionConverter::convert(const Fraction& f, void* args)
{
    auto lowest = f.lowestTerm();
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

string FractionToDecimalConverter::convert(const Fraction& f, void* args)
{
    float value = ((float)f.Numerator()) / f.Denominator();
    int* precision = (int*)args;
    int number = *precision;

    stringstream builder;

    builder << setprecision(number) << value;

    string result = builder.str();
    return result;
}