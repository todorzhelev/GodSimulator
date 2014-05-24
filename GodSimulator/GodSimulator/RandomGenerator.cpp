#include"RandomGenerator.h"

RandomGenerator* RandomGenerator::rger = nullptr;

RandomGenerator::RandomGenerator()
{
	int a = 5;

}

string RandomGenerator::GenerateRandomString(int nLength)
{
	return "";
}

double RandomGenerator::GenerateRandomNumber(int nUpperRange)
{
	int nNumber = rand() % nUpperRange;
	
	return (double)nNumber;
}

RandomGenerator* RandomGenerator::GetRGen()
{
	if( rger == nullptr )
	{
		rger  = new RandomGenerator;
	}
		
	return rger;
}
