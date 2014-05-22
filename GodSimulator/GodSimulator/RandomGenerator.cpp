#include"RandomGenerator.h"

RandomGenerator::RandomGenerator()
{
	int a = 5;

}

string RandomGenerator::GenerateRandomString(int nLength)
{
	return "";
}

double RandomGenerator::GenerateRandomNumber(int nUpperRange, bool bCanBeNegative)
{
	int nNumber = rand() % nUpperRange;
	
	return (double)nNumber;
}
