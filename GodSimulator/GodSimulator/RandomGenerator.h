#include<string>
#include<time.h>
#include <stdlib.h> 

#pragma once

using namespace std;

class RandomGenerator
{
public:

	RandomGenerator();

	string GenerateRandomString(int nLength);

	double GenerateRandomSignedNumber(int nUpperRange);

	double GenerateRandomNumber(int nUpperRange);

	int GenerateRandomNumberInRange(int nLowerRange, int nUpperRange);

	char GenerateRandomChar(bool bIsCapital);

	static RandomGenerator* GetRGen();

private:

	static RandomGenerator* rger;
};

