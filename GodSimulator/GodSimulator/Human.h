#include"Animal.h"

#pragma once

class Human : public Animal
{
public:

	Human();

	void Analyze();
	
	void Attack(Entity& otherEntity);
	void Mate(unique_ptr<Planet>& pPlanet);
	virtual void DoAction(unique_ptr<Planet>& pPlanet,Entity& otherEntity);

};