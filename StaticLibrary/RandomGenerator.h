#pragma once
#include "Standard.h"

class RandomGenerator
{
private:
	inline static std::shared_ptr<RandomGenerator> _instance = nullptr;
	RandomGenerator();

public:
	static std::shared_ptr <RandomGenerator> Instance();

public:
	virtual int next();
	virtual int next(int, int);
	virtual int next(int);
};
