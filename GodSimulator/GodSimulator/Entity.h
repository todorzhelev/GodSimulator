#include<string>
#include"Point3D.h"
using namespace std;

#pragma once 

class Entity
{
public:

	Entity();
	Entity(string name,double energy,double level,Point3D position);

	string GetName();
	void SetName(string name);

	double GetEnergy();
	void SetEnergy(double energy);

	double GetLevel();
	void SetLevel(double level);

	Point3D GetPosition();
	void SetPosition(Point3D position);

	double GetSize();
	double GetMass();
	
	void Move(Point3D amountTravelled);



private:
	void CalculateSize();
	void CalculateMass();

	string m_strName;
	double m_fEnergy;
	double m_fSize;
	double m_fMass;
	int m_nLevel;
	Point3D m_Position;
};