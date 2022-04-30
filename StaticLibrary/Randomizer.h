#pragma once
#include "Standard.h"

class Randomizer
{
private:
	inline static Randomizer* _instance = nullptr;
	Randomizer();

public:
	static Randomizer* Instance();

public:
	virtual int next();
	virtual int next(int, int);
	virtual int next(int);
};
