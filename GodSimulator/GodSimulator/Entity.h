#include<string>
#include<iostream>
#include"Point3D.h"
#include"RandomGenerator.h"
#include<memory>

#pragma once 

class Planet;

enum class EntityType
{
	BasicEntity,
	AnimalType,
	HumanType,
	GodType,
	UnknownType
};

enum class States
{
	Unknown,
	Moving,
	Attacking,
	Eating,
	SearchingForFood,
	Sleeping,
	Analyzing
};

class Entity
{
public:

	Entity();
	Entity(std::string name,double energy,Point3D position);

	std::string GetName();
	void SetName(std::string name);

	double GetEnergy();
	void SetEnergy(double energy);
	void ModifyEnergy(double energy);

	Point3D GetPosition() const;
	void SetPosition(Point3D position);

	double GetSize();
	double GetMass();
	
	void Move(Point3D amountTravelled);

	void Attack(Entity& otherEntity);

	virtual void DoAction(std::unique_ptr<Planet>& pPlanet,Entity& otherEntity);

	void SetState(States state);
	States GetState();

	int GetStrength();
	void SetStrength(int strength);

protected:
	void CalculateSize();
	void CalculateMass();

	std::string	 m_strName;
	double		 m_fEnergy;
	double		 m_fSize;
	double		 m_fMass;
	Point3D		 m_Position;
	int			 m_nStrength;
	States		 m_State;
};