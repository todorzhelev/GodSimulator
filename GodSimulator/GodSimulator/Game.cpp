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

	pPlayer->InitPopulation(*planet,EntityType::BasicEntity,5000);

	map<string,string> closeEntities;

	cout << "Hello, God " << pPlayer->GetName() << endl;

	using namespace std::placeholders;

	std::thread ParallelThread(&Game::GetCommand,this);

	while(true)
	{
		ParallelCode();

		if( m_bShouldExecuteCommand )
		{
			m_pCommandManager->ExecuteCommand(m_pCommandManager->GetLastCommand());
			m_bShouldExecuteCommand = false;
		}

	/*	
		for( auto& i :planet->m_vEntities )
		{
			for( auto& j: planet->m_vEntities )
			{
				if( i!= j && pPhysics->IsClose(*i,*j) && closeEntities[i->GetName()].empty())
				{
					closeEntities[i->GetName()] = j->GetName();
					cout << i->GetName() << " and " << j->GetName() << " are close" << endl;
				}
			}

		}*/
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
			cout << "Type \"destroy \(planet name\)\" to destroy planet's population" << endl;
			cout << "Type \"list\" to print the current available planets with their population" << endl;
			cout << "Type \"exit\" to exit the simulator" << endl;

			string command;
			getline(cin,command);

			vector<string> commands = m_pCommandManager->ParseCommand(command);
		
			m_bShouldExecuteCommand = true;

			bShouldShow = true;
		}
	}
}

void Game::ParallelCode()
{
	for( auto& i: m_pScene->GetPlanets() )
	{
		if( !i->m_vEntities.empty() )
		{
			for( auto& k :i->m_vEntities )
			{

			}
		}
	}
}