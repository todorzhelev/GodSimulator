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

	void ParallelCode();

private:

	std::mutex mutex;

	Physics* m_pPhysics;

	God* pPlayer;

	Scene* m_pScene;

	CommandManager* m_pCommandManager;

	//function<void(string)> ExecuteCommandFunctor;

	bool m_bShouldExecuteCommand;

};