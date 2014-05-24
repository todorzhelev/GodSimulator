#include"Entity.h"

Entity::Entity()
{
	m_strName = "asdf";
	m_fEnergy = RandomGenerator::GetRGen()->GenerateRandomNumber(100);
	m_nLevel = 0;

	double x = RandomGenerator::GetRGen()->GenerateRandomNumber(10000);
	double y = RandomGenerator::GetRGen()->GenerateRandomNumber(10000);
	double z = RandomGenerator::GetRGen()->GenerateRandomNumber(10000);

	m_Position = Point3D(x,y,z);

	CalculateSize();
	CalculateMass();
}

Entity::Entity(string name,double energy,double level,Point3D position)
{
	m_strName = name;
	m_fEnergy = energy;
	m_nLevel = level;
	m_Position = position;

	CalculateSize();
	CalculateMass();
}

string Entity::GetName()
{
	return m_strName;
}

void Entity::SetName(string name)
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

double Entity::GetLevel()
{
	return m_nLevel;
}

void Entity::SetLevel(double level)
{
	m_nLevel = level;
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
	m_fSize = m_fEnergy+m_nLevel;
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

void Entity::Move(Point3D amountTravelled)
{
	m_Position.SetX(m_Position.GetX()+amountTravelled.GetX());
	m_Position.SetY(m_Position.GetY()+amountTravelled.GetY());
	m_Position.SetZ(m_Position.GetZ()+amountTravelled.GetZ());
}