#include"Animal.h"

#pragma once

class Human : public Animal
{
public:

	Human();

	void Analyze();
	
	virtual void Attack(Entity& otherEntity);


private:

	double m_fWillForce;
	double m_fIntellect;
	double m_fDepressionLevel;




};