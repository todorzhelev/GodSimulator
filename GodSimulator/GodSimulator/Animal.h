#include"Entity.h"

#pragma once

class Animal: public Entity
{
public:

	Animal();

	void Sleep();
	void SearchForFood();
	void Eat();

	void Attack(Entity& otherEntity);
	void Mate(unique_ptr<Planet>& pPlanet);

	virtual void DoAction(unique_ptr<Planet>& pPlanet,Entity& otherEntity);

private:


};