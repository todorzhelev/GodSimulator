#include"Animal.h"

#pragma once

class Human : public Animal
{
public:

	Human();

	void Analyze();
	
	void Attack(Entity& otherEntity);
	void Mate(std::unique_ptr<Planet>& pPlanet);
	virtual void DoAction(std::unique_ptr<Planet>& pPlanet,Entity& otherEntity);

};