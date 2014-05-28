#include<string>
#include<iostream>
#include"Point3D.h"
#include"RandomGenerator.h"
#include<memory>
using namespace std;

#pragma once 

enum EntityType
{
	BasicEntity,
	AnimalType,
	HumanType,
	GodType
};

class Entity
{
public:

	Entity();
	Entity(string name,double energy,double level,Point3D position);

	string GetName();
	void SetName(string name);

	double GetEnergy();
	void SetEnergy(double energy);
	void ModifyEnergy(double energy);

	double GetLevel();
	void SetLevel(double level);

	Point3D GetPosition() const;
	void SetPosition(Point3D position);

	double GetSize();
	double GetMass();
	
	void Move(Point3D amountTravelled);

	virtual void Attack(Entity& otherEntity);

	int GetStrength();
	void SetStrength(int strength);

protected:
	void CalculateSize();
	void CalculateMass();

	string m_strName;
	double m_fEnergy;
	double m_fSize;
	double m_fMass;
	int m_nLevel;
	Point3D m_Position;
	int m_nStrength;
};