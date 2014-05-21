#include"Entity.h"

#pragma once

class Animal: public Entity
{
public:

	Animal();

	void Attack(const Entity& entity);
	void Sleep();
	void SearchForFood();
	void Eat();




private:








};