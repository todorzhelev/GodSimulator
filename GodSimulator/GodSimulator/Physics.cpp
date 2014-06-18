#include"Physics.h"

const double dist = 300;
const int nLowerBound = 0;
const int nUpperBound = 15000;
const int nMoveRate = 1000;

bool Physics::IsClose(const Entity& ent1,const Entity& ent2)
{
	return  ent1.GetPosition().GetDistance(ent2.GetPosition()) < dist;
}

void Physics::MoveEntity(Entity& ent)
{
	double dx = RandomGenerator::GetRGen()->GenerateRandomSignedNumber(nMoveRate);
	double dy = RandomGenerator::GetRGen()->GenerateRandomSignedNumber(nMoveRate);
	double dz = RandomGenerator::GetRGen()->GenerateRandomSignedNumber(nMoveRate);

	//restrict the entities into bounds
	if( ent.GetPosition().GetX()+dx < nLowerBound || ent.GetPosition().GetX()+dx >nUpperBound  )
	{
		dx = 0;
	}
	if( ent.GetPosition().GetY()+dy < nLowerBound || ent.GetPosition().GetY()+dy >nUpperBound)
	{
		dy = 0;
	}
	if( ent.GetPosition().GetX()+dz < nLowerBound  || ent.GetPosition().GetZ()+dz >nUpperBound)
	{
		dz = 0;
	}
	ent.Move(Point3D(dx,dy,dz));
}