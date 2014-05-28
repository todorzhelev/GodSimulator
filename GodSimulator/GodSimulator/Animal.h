#include"Entity.h"

#pragma once

class Animal: public Entity
{
public:

	Animal();

	void Sleep();
	void SearchForFood();
	void Eat();

	virtual void Attack(Entity& otherEntity);



private:


};