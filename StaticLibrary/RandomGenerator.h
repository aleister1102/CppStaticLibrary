#pragma once
#include "Standard.h"

class RandomGenerator
{
private:
	inline static RandomGenerator* _instance = nullptr;
	RandomGenerator();

public:
	static RandomGenerator* Instance();

public:
	virtual int next();
	virtual int next(int, int);
	virtual int next(int);
};
