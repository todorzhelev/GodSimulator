#include<map>
#include<thread>
#include"RandomGenerator.h"
#include"Scene.h"
#include"God.h"
#include"Physics.h"
#include"CommandManager.h"

#pragma once

class Game
{
public:

	Game();

	void GetCommand();

	void Run();

	void Update();

	void PrintOptions();

private:

	Physics* m_pPhysics;

	God* m_pPlayer;

	CommandManager* m_pCommandManager;

	bool m_bShouldExecuteCommand;
};