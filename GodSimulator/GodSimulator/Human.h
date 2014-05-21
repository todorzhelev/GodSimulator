#include"Animal.h"

#pragma once

class Human : public Animal
{
	Human();

	void Analyze();
	

private:

	double m_fWillForce;
	double m_fIntellect;
	double m_fDepressionLevel;




};