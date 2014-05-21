#include"RandomGenerator.h"


string RandomGenerator::GenerateRandomString(int nLength)
{
	return "";
}

double RandomGenerator::GenerateRandomNumber(int nUpperRange, bool bCanBeNegative)
{
	int nNumber = rand() % nUpperRange;
	
	return (double)nNumber;
}
