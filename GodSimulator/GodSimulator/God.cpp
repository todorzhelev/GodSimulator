#include"God.h"


void God::AddEntities(Planet& planet, EntityType type, int amount)
{
	for(int i = 0; i < amount;i++)
	{
		unique_ptr<Entity> pEntity = move(m_pScene->CreateEntity(type));

		planet.m_vEntities.push_back(move(pEntity));
	}
}


void God::DestroyEntirePopulation(Planet& planet)
{
	planet.m_vEntities.erase(planet.m_vEntities.begin(),planet.m_vEntities.end());
}

void God::CreatePlanet()
{
	unique_ptr<Planet> pPlanet(new Planet);

	m_pScene->GetPlanets().push_back(move(pPlanet));
}

void God::Attack(Entity& otherEntity)
{
	int damage = RandomGenerator::GetRGen()->GenerateRandomNumber(m_nStrength)*40000;

	otherEntity.ModifyEnergy(-damage);
}