#include"Game.h"

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
	unique_ptr<Planet> pPlanet(new Planet);

	m_pScene->GetPlanets().push_back(move(pPlanet));

	pPlayer->AddEntities(*(m_pScene->GetPlanets().front()),EntityType::HumanType,200);

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

			PrintOptions();

			string command;
			getline(cin,command);

			m_pCommandManager->ParseCommand(command);
		
			m_bShouldExecuteCommand = true;
			bShouldShow = true;	
		}
	}
}

void Game::PrintOptions()
{
	cout << "You can choose on of the following options:" << endl;
	cout << "Type \"destroy (planet name)\" to destroy planet's population" << endl;
	cout << "Type \"list\" to print the current available planets with their population" << endl;
	cout << "Type \"add (planet name) (entity,animal,human or god) (entity amount)\" to add population to a planet" << endl;
	cout << "Type \"create\" to create random planet" << endl;
	cout << "Type \"exit\" to exit the simulator" << endl;
}

void Game::Update()
{
	//removes all dead entities and adds the newly created entities
	for( auto& i: m_pScene->GetPlanets() )
	{
		//lambda function to test the entity energy
		auto func = [](unique_ptr<Entity>& ent){return ent->GetEnergy() < 0;};

		//all entities that have their energy below zero are moved at the end of the array with remove_if function.
		//then they are all erased with the erase function
		i->m_vEntities.erase(remove_if(i->m_vEntities.begin(), i->m_vEntities.end(),func),
							 i->m_vEntities.end());

		//add new entities
		for( auto it = i->m_EntitiesToBeAdded.begin();it!=i->m_EntitiesToBeAdded.end();it++)
		{
			for( int j = 0; j < it->second;j++)
			{
				unique_ptr<Entity> pEntity = move(m_pScene->CreateEntity(it->first));

				i->m_vEntities.push_back(move(pEntity));
			}
		}

		i->m_EntitiesToBeAdded.clear();
	}

	//moves entites around
	for( auto& i: m_pScene->GetPlanets() )
	{
		for(auto it = i->m_vEntities.begin(); it!= i->m_vEntities.end();it++)
		{
				m_pPhysics->MoveEntity(*(*it));
		}
	}

	for( auto& i: m_pScene->GetPlanets() )
	{
		i->SortEntities();
	}

	//after the entities are sorted by distance from the beginning
	//we watch only for two consequent entities in the vector, since they have the chance
	//to be close enough
	for( auto& k: m_pScene->GetPlanets() )
	{
		for(auto it = k->m_vEntities.begin(); it!= k->m_vEntities.end();it++)
		{
			auto nextEntity = it;
			nextEntity++;

			if( nextEntity != k->m_vEntities.end() && m_pPhysics->IsClose(*(*it),*(*nextEntity)) )
			{
				(*it)->DoAction(k,*(*nextEntity));
			}
		}
	}
}