#include "Randomizer.h"

Randomizer* Randomizer::Instance()
{
	if (_instance == nullptr)
	{
		_instance = new Randomizer();
	}

	return _instance;
}

/**
 * @brief Init time seed
 */
Randomizer::Randomizer()
{
	srand(time(NULL));
}

/**
 * @brief Create a integer Randomizer number (from 0 to 32767)
 *
 * @return Integer number
 */
int Randomizer::next()
{
	int num = rand();
	return num;
}

/**
 * @brief Create a ramdom integer in [min, max]
 *
 * @param min upper boundary
 * @param max lower boundary
 * @return Integer number
 */
int Randomizer::next(int min, int max)
{
	int num = rand() % (max - min + 1) + min;
	return num;
}

/**
 * @brief Creata a Randomizer integer in [0, ceiling)
 *
 * @param ceiling upper boundary, but not included
 * @return Integer number
 */
int Randomizer::next(int ceiling)
{
	int num = rand() % ceiling;
	return num;
}