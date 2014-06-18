#include"Human.h"
#include"Planet.h"
#include"Scene.h"

#pragma once

class God : public Human
{
public:

	void DestroyEntirePopulation(Planet& planet);
	void AddEntities(Planet& planet, EntityType type, int amount);
	void CreatePlanet();
	void Attack(Entity& otherEntity);

	void Mate(std::unique_ptr<Planet>& pPlanet);
	virtual void DoAction(std::unique_ptr<Planet>& pPlanet,Entity& otherEntity);
};