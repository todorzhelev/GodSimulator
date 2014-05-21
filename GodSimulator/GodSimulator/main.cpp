#include<iostream>
#include"Entity.h"
#include"Animal.h"
#include"RandomGenerator.h"

int main()
{
	RandomGenerator gen;
	srand(time(NULL));

	for( int i = 0; i < 10; i++)
	{
		cout << gen.GenerateRandomNumber(1000,true) << endl;
	}

	Entity* pEnt = new Entity("pesho",80,1,Point3D(1,1,1));

	pEnt->Move(Point3D(10,15,-3));

	Animal* anim = new Animal();

	system("pause");
	return 0;
}