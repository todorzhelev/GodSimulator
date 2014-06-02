#include"Human.h"


Human::Human()
{



}

void Human::Attack(Entity& otherEntity)
{
	int damage = RandomGenerator::GetRGen()->GenerateRandomNumber(m_nStrength)*5;

	otherEntity.ModifyEnergy(-damage);
}