#include"Game.h"
#include<thread>

Game::Game()
{
	srand(time(NULL));

	m_pScene = new Scene;

	pPlayer = new God;

	m_pPhysics = new Physics;

	m_pCommandManager = new CommandManager(pPlayer,m_pScene);
}

void Game::Run()
{
	Planet* planet = new Planet;

	m_pScene->GetPlanets().push_back(planet);

	pPlayer->InitPopulation(*planet,EntityType::BasicEntity,200);

	map<string,string> closeEntities;

	cout << "Hello, God " << pPlayer->GetName() << endl;

	//the thread will be immediately started after next line
	std::thread ParallelThread(&Game::GetCommand,this);

	while(true)
	{
		Update();

		if( m_bShouldExecuteCommand )
		{
			m_pCommandManager->ExecuteCommand(m_pCommandManager->GetLastCommand());
			m_bShouldExecuteCommand = false;
		}
	}

	ParallelThread.join();
	
}

void Game::GetCommand()
{
	while( true)
	{
		static bool bShouldShow = true;
		if( bShouldShow && !m_bShouldExecuteCommand )
		{
			
			m_bShouldExecuteCommand = false;

			bShouldShow = false;
			cout << "You can choose on of the following options:" << endl;
			cout << "Type \"destroy (planet name)\" to destroy planet's population" << endl;
			cout << "Type \"list\" to print the current available planets with their population" << endl;
			cout << "Type \"init (entity type) (entity amount)\" to add population to a planet" << endl;
			cout << "Type \"exit\" to exit the simulator" << endl;

			string command;
			getline(cin,command);

			vector<string> commands = m_pCommandManager->ParseCommand(command);
		
			m_bShouldExecuteCommand = true;

			bShouldShow = true;
			
		}
	}
}

void Game::Update()
{
	for( auto& i: m_pScene->GetPlanets() )
	{
		for(auto it = i->m_vEntities.begin(); it!= i->m_vEntities.end();)
		{
			int energy = (*it).second->GetEnergy();
			if( (*it).second->GetEnergy() < 0 )
			{
				i->m_vEntities.erase(it++);
			}
			else
			{
				m_pPhysics->MoveEntity(*((*it).second));
				it++;
			}
		}
	}

	for( auto& k: m_pScene->GetPlanets() )
	{
		for( auto& i :k->m_vEntities )
		{
			for( auto& j: k->m_vEntities )
			{
				if( i!= j && m_pPhysics->IsClose(*(i.second),*(j.second)) )
				{
					i.second->Attack(*(j.second));

				}
			}

		}
	}
}