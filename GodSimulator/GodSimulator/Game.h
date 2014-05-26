#include"Entity.h"
#include"Animal.h"
#include"RandomGenerator.h"
#include"God.h"
#include"Scene.h"
#include"Planet.h"
#include"Physics.h"
#include"CommandManager.h"
#include<map>

#pragma once

class Game
{
	
public:

	Game();

	void GetCommand();

	void Run();

private:

	God* pPlayer;

	Scene* m_pScene;

	CommandManager* m_pCommandManager;
};