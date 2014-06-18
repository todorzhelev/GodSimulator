#include"Entity.h"

Entity::Entity()
{
	int nNameLenght = RandomGenerator::GetRGen()->GenerateRandomNumberInRange(4,6);

	m_strName = RandomGenerator::GetRGen()->GenerateRandomString(nNameLenght);

	m_fEnergy = RandomGenerator::GetRGen()->GenerateRandomNumber(100);

	double x = RandomGenerator::GetRGen()->GenerateRandomNumber(10000);
	double y = RandomGenerator::GetRGen()->GenerateRandomNumber(10000);
	double z = RandomGenerator::GetRGen()->GenerateRandomNumber(10000);

	m_Position = Point3D(x,y,z);

	m_nStrength = (int)m_fEnergy*(RandomGenerator::GetRGen()->GenerateRandomNumber(5));

	CalculateSize();
	CalculateMass();
}

Entity::Entity(std::string name,double energy,Point3D position)
{
	m_strName = name;
	m_fEnergy = energy;
	m_Position = position;

	m_nStrength = (int)m_fEnergy*RandomGenerator::GetRGen()->GenerateRandomNumber(5);
	CalculateSize();
	CalculateMass();
}

std::string Entity::GetName()
{
	return m_strName;
}

void Entity::SetName(std::string name)
{
	m_strName = name;
}

double Entity::GetEnergy()
{
	return m_fEnergy;
}
void Entity::SetEnergy(double energy)
{
	m_fEnergy = energy;
}

void Entity::ModifyEnergy(double energy)
{
	m_fEnergy+=energy;
}

Point3D Entity::GetPosition() const
{
	return m_Position;
}
void Entity::SetPosition(Point3D position)
{
	m_Position = position;
}

void Entity::CalculateSize()
{
	m_fSize = m_fEnergy*2;
}

void Entity::CalculateMass()
{
	m_fMass = m_fSize*m_fEnergy;
}

double Entity::GetSize()
{
	return m_fSize;
}

double Entity::GetMass()
{
	return m_fMass;
}

int Entity::GetStrength()
{
	return m_nStrength;
}
void Entity::SetStrength(int strength)
{
	m_nStrength = strength;
}

void Entity::SetState(States state)
{
	m_State = state;
}
States Entity::GetState()
{
	return m_State;
}

void Entity::Move(Point3D amountTravelled)
{
	m_Position.SetX(m_Position.GetX()+amountTravelled.GetX());
	m_Position.SetY(m_Position.GetY()+amountTravelled.GetY());
	m_Position.SetZ(m_Position.GetZ()+amountTravelled.GetZ());
}

void Entity::Attack(Entity& otherEntity)
{
	int damage = RandomGenerator::GetRGen()->GenerateRandomNumber(m_nStrength);

	otherEntity.ModifyEnergy(-damage);
}

void Entity::DoAction(std::unique_ptr<Planet>& pPlanet,Entity& otherEntity)
{
	Attack(otherEntity);
}