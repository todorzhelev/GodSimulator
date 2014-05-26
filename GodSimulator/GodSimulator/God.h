#include"Human.h"
#include"Planet.h"

#pragma once

class God : public Human
{
public:

	void DestroyEntirePopulation(Planet& planet);
	void BindEntitiesToNewPlanet(const Planet& oldPlanet,const Planet& newPlanet);

	void InitPopulation(Planet& planet, EntityType type, int amount);

	void SpreadDisease(const Planet& planet, const Point3D& initialPosition);

	void CreateEarthquake(const Planet& planet,const Point3D& initialPosition,double force, double duration);


private:

	int artefact;

};