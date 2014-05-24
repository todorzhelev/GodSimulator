#include"God.h"


void God::InitPopulation(Planet& planet, EntityType type, int amount)
{
	for(int i = 0; i < amount;i++)
	{
		Entity* pEntity = new Human;

		planet.m_vEntities.push_back(pEntity);
	}
}