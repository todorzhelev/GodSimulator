#include"Game.h"
#include<thread>

Game::Game()
{
	srand(time(NULL));

	m_pScene = new Scene;

	pPlayer = new God;

	m_pPhysics = new Physics;

	m_pCommandManager = new CommandManager(pPlayer,m_pScene);

	//stream.open("log.txt");
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
		if( m_bShouldExecuteCommand )
		{
			m_pCommandManager->ExecuteCommand(m_pCommandManager->GetLastCommand());
			m_bShouldExecuteCommand = false;
		}

		Update();
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

bool IsEnergyBelowZero(const unique_ptr<Entity>& ent)
{
	return ent->GetEnergy() < 0;
}

void Game::Update()
{
	//stream << "Starting Update method" << endl;

	//auto start_time = chrono::high_resolution_clock::now();
	for( auto& i: m_pScene->GetPlanets() )
	{
		i->m_vEntities.erase(std::remove_if(i->m_vEntities.begin(), i->m_vEntities.end(), IsEnergyBelowZero),i->m_vEntities.end());
	}
	//auto end_time = chrono::high_resolution_clock::now();

	//stream << "Deletion dead entities " << chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count() << " ms" << endl;

	//start_time = chrono::high_resolution_clock::now();
	for( auto& i: m_pScene->GetPlanets() )
	{
		for(auto it = i->m_vEntities.begin(); it!= i->m_vEntities.end();it++)
		{
				m_pPhysics->MoveEntity(*(*it));
		}
	}
	//end_time = chrono::high_resolution_clock::now();

	//stream << "Moving entities " << chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count() << " ms"<< endl;

	//start_time = chrono::high_resolution_clock::now();
	for( auto& i: m_pScene->GetPlanets() )
	{
		i->SortEntities();
	}
	//end_time = chrono::high_resolution_clock::now();

	//stream << "Sorting entities " << chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count() << " ms"<< endl;

	//start_time = chrono::high_resolution_clock::now();
	for( auto& k: m_pScene->GetPlanets() )
	{
		for(auto it = k->m_vEntities.begin(); it!= k->m_vEntities.end();it++)
		{
			auto nextEntity = it;
			nextEntity++;

			if( nextEntity != k->m_vEntities.end() && m_pPhysics->IsClose(*(*it),*(*nextEntity)) )
			{
				(*it)->Attack(*(*nextEntity));
			}
		}
	}
	//end_time = chrono::high_resolution_clock::now();

	//stream << "Attacking close entities " << chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count() << " ms" << endl;

	//stream << "End of Update method " << endl << "--------------------------------------------------------" << endl;
}