#include"Physics.h"

const double dist = 1000;

bool Physics::IsClose(const Entity& ent1,const Entity& ent2)
{
	return  ent1.GetPosition().GetDistance(ent2.GetPosition()) < dist;
}