#include"Animal.h"
#include"Scene.h"

Animal::Animal()
{


}
void Animal::Attack(Entity& otherEntity)
{
	int damage = RandomGenerator::GetRGen()->GenerateRandomNumber(m_nStrength)*3;

	otherEntity.ModifyEnergy(-damage);
}

void Animal::Sleep()
{
	m_State = States::Sleeping;
}

void Animal::SearchForFood()
{
	m_State = States::SearchingForFood;
}

void Animal::Eat()
{
	m_State = States::Eating;
}

void Animal::Mate(unique_ptr<Planet>& pPlanet)
{
	pPlanet->m_EntitiesToBeAdded[EntityType::AnimalType]++;
}

void Animal::DoAction(unique_ptr<Planet>& pPlanet,Entity& otherEntity)
{
	int number = RandomGenerator::GetRGen()->GenerateRandomNumber(5);
	switch(number)
	{
		case 1: Attack(otherEntity); break;
		case 2: Sleep(); break;
		case 3: SearchForFood(); break;
		case 4: Eat(); break;
		case 5: Mate(pPlanet); break;
	};		 
}