#include"Physics.h"

const double dist = 300;

bool Physics::IsClose(const Entity& ent1,const Entity& ent2)
{
	return  ent1.GetPosition().GetDistance(ent2.GetPosition()) < dist;
}

void Physics::MoveEntity(Entity& ent)
{
	double dx = RandomGenerator::GetRGen()->GenerateRandomSignedNumber(1000);
	double dy = RandomGenerator::GetRGen()->GenerateRandomSignedNumber(1000);
	double dz = RandomGenerator::GetRGen()->GenerateRandomSignedNumber(1000);

	if( ent.GetPosition().GetX()+dx < 0 )
	{
		dx = 0;
	}
	if( ent.GetPosition().GetY()+dy < 0 )
	{
		dy = 0;
	}
	if( ent.GetPosition().GetX()+dz < 0 )
	{
		dz = 0;
	}
	ent.Move(Point3D(dx,dy,dz));
}