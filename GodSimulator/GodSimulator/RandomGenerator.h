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

	double GenerateRandomNumber(int nUpperRange, bool bCanBeNegative);

};
