#include"Entity.h"
#include"Animal.h"
#include"RandomGenerator.h"
#include"God.h"

#pragma once

class Game
{
	
public:

	Game();

	void Run();

private:

	RandomGenerator* rgen;

	God* pPlayer;
};