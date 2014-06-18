#include"RandomGenerator.h"

RandomGenerator* RandomGenerator::m_pRGen = nullptr;

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

//generates random string in the format capital letter first, then lower letters only
std::string RandomGenerator::GenerateRandomString(int nLength)
{
	std::string strName;

	strName.resize(nLength);

	//the first symbol will be capital letter
	strName[0] = GenerateRandomChar(true);

	for( int i = 1; i < nLength; i++)
	{
		strName[i] = GenerateRandomChar(false);
	}

	return strName;
}

int RandomGenerator::GenerateRandomNumber(int nUpperRange)
{
	int nNumber = rand() % nUpperRange;
	
	//always return numbers greater than zero
	return nNumber+1;
}

double RandomGenerator::GenerateRandomSignedNumber(int nUpperRange)
{
	int nNumber = rand() % nUpperRange;

	//adds additional randomization. if nNumber is even make it negative.
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
	if( m_pRGen == nullptr )
	{
		m_pRGen  = new RandomGenerator;
	}
		
	return m_pRGen;
}
