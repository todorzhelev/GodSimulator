#include"RandomGenerator.h"

RandomGenerator* RandomGenerator::rger = nullptr;

RandomGenerator::RandomGenerator()
{}

char RandomGenerator::GenerateRandomChar(bool bIsCapital)
{
	char randomChar;

	const int nACapitalAsciiCode = 65;
	const int nZCapitalAsciiCode = 90;

	const int nALowerAsciiCode = 97;
	const int nZLowerAsciiCode = 122;

	if( bIsCapital )
	{
		randomChar = static_cast<char>(GenerateRandomNumberInRange(nACapitalAsciiCode,nZCapitalAsciiCode));
	}
	else
	{
		randomChar = static_cast<char>(GenerateRandomNumberInRange(nALowerAsciiCode,nZLowerAsciiCode));
	}
	

	return randomChar;

}

string RandomGenerator::GenerateRandomString(int nLength)
{
	string strName;

	strName.resize(nLength);

	strName[0] = GenerateRandomChar(true);

	for( int i = 1; i < nLength; i++)
	{
		strName[i] = GenerateRandomChar(false);
	}

	return strName;
}

double RandomGenerator::GenerateRandomNumber(int nUpperRange)
{
	int nNumber = rand() % nUpperRange;
	
	return (double)nNumber;
}

double RandomGenerator::GenerateRandomSignedNumber(int nUpperRange)
{
	int nNumber = rand() % nUpperRange;

	if( nNumber % 2 == 0 )
	{
		nNumber = -nNumber;
	}
	
	return (double)nNumber;
}

int RandomGenerator::GenerateRandomNumberInRange(int nLowerRange, int nUpperRange)
{
	int nNumber = rand() % (nUpperRange-nLowerRange);
	
	return nLowerRange+nNumber;
}

RandomGenerator* RandomGenerator::GetRGen()
{
	if( rger == nullptr )
	{
		rger  = new RandomGenerator;
	}
		
	return rger;
}
