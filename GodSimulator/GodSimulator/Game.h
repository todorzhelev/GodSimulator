#include"Entity.h"
#include"Animal.h"
#include"RandomGenerator.h"
#include"God.h"
#include"Scene.h"
#include"Planet.h"
#include"Physics.h"
#include"CommandManager.h"
#include<map>
#include<mutex>

#pragma once

class Game
{
	
public:

	Game();

	void GetCommand();

	void Run();

	void Update();

private:

	mutex m_mutex;

	Physics* m_pPhysics;

	God* pPlayer;

	CommandManager* m_pCommandManager;

	bool m_bShouldExecuteCommand;

};