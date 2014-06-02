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
	virtual void Attack(Entity& otherEntity);
};