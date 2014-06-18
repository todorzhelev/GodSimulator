#include"Human.h"
#include"Scene.h"

Human::Human()
{
}

void Human::Analyze()
{
	m_State = States::Analyzing;
}

void Human::Attack(Entity& otherEntity)
{
	int damage = RandomGenerator::GetRGen()->GenerateRandomNumber(m_nStrength)*5;

	otherEntity.ModifyEnergy(-damage);
}

void Human::Mate(std::unique_ptr<Planet>& pPlanet)
{
	pPlanet->GetEntitiesToBeAdded()[EntityType::HumanType]++;
}

void Human::DoAction(std::unique_ptr<Planet>& pPlanet,Entity& otherEntity)
{
	int number = RandomGenerator::GetRGen()->GenerateRandomNumber(6);
	switch(number)
	{
		case 1: Attack(otherEntity); break;
		case 2: Sleep(); break;
		case 3: SearchForFood(); break;
		case 4: Eat(); break;
		case 5: Mate(pPlanet); break;
		case 6: Analyze(); break;
	};
}