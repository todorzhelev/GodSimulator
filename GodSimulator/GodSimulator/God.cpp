#include"God.h"


void God::InitPopulation(Planet& planet, EntityType type, int amount)
{
	for(int i = 0; i < amount;i++)
	{
		unique_ptr<Entity> pEntity(new Human());

		planet.m_vEntities.push_back(move(pEntity));
	}
}


void God::DestroyEntirePopulation(Planet& planet)
{
	planet.m_vEntities.erase(planet.m_vEntities.begin(),planet.m_vEntities.end());
}