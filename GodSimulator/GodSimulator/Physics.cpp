#include"Physics.h"

const double dist = 300;

bool Physics::IsClose(const Entity& ent1,const Entity& ent2)
{
	return  ent1.GetPosition().GetDistance(ent2.GetPosition()) < dist;
}

void Physics::MoveEntity(Entity& ent)
{
	double dx = RandomGenerator::GetRGen()->GenerateRandomNumber(10);
	double dy = RandomGenerator::GetRGen()->GenerateRandomNumber(10);
	double dz = RandomGenerator::GetRGen()->GenerateRandomNumber(10);

	ent.Move(Point3D(dx,dy,dz));
}