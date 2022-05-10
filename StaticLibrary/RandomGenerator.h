#pragma once
#include "Standard.h"

class RandomGenerator
{
private:
	inline static shared_ptr<RandomGenerator> _instance = nullptr;
	RandomGenerator();

public:
	static shared_ptr <RandomGenerator> Instance();

public:
	virtual int next();
	virtual int next(int, int);
	virtual int next(int);
};
