#include<string>

#pragma once

class RandomGenerator
{
public:

	RandomGenerator();

	std::string GenerateRandomString(int nLength);

	double GenerateRandomSignedNumber(int nUpperRange);

	int GenerateRandomNumber(int nUpperRange);

	int GenerateRandomNumberInRange(int nLowerRange, int nUpperRange);

	char GenerateRandomChar(bool bIsCapital);

	static RandomGenerator* GetRGen();

private:

	static RandomGenerator* m_pRGen;
};

