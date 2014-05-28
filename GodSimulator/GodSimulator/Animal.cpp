#include"Animal.h"

Animal::Animal()
{


}
void Animal::Attack(Entity& otherEntity)
{
	int damage = RandomGenerator::GetRGen()->GenerateRandomNumber(m_nStrength)*3;

	otherEntity.ModifyEnergy(damage);
}

void Animal::Sleep()
{

}

void Animal::SearchForFood()
{

}

void Animal::Eat()
{


}