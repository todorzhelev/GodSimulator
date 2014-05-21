#include"Entity.h"

int main()
{
	Entity* pEnt = new Entity("pesho",80,1,Point3D(1,1,1));

	pEnt->Move(Point3D(10,15,-3));

	return 0;
}