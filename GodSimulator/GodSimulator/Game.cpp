#include"Game.h"

/*/////////////////////////////////////////////////////////////
Repository in GitHub : https://github.com/toshle05/GodSimulator
*//////////////////////////////////////////////////////////////

Game::Game()
{
	srand(time(NULL));

	m_pScene = new Scene;

	m_pPlayer = new God;

	m_pPhysics = new Physics;

	m_pCommandManager = new CommandManager(m_pPlayer,m_pScene);
}

void Game::Run()
{
	using namespace std;

	unique_ptr<Planet> pPlanet(new Planet());

	m_pScene->GetPlanets().push_back(move(pPlanet));

	m_pPlayer->AddEntities(*(m_pScene->GetPlanets().front()),EntityType::HumanType,200);

	cout << "Hello, God " << m_pPlayer->GetName() << endl;

	//the thread will be immediately started after next line
	std::thread PlayerInputThread(&Game::GetCommand,this);

	while(true)
	{
		if( m_bShouldExecuteCommand )
		{
			m_pCommandManager->ExecuteCommand(m_pCommandManager->GetLastCommand());
			m_bShouldExecuteCommand = false;
		}

		Update();
	}

	PlayerInputThread.join();
	
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

			std::string command;
			getline(std::cin,command);

			m_pCommandManager->ParseCommand(command);
		
			m_bShouldExecuteCommand = true;
			bShouldShow = true;	
		}
	}
}

void Game::PrintOptions()
{
	using namespace std;

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
		auto func = [](std::unique_ptr<Entity>& ent){return ent->GetEnergy() < 0;};

		//all entities that have their energy below zero are moved at the end of the array with remove_if function.
		//then they are all erased with the erase function
		i->GetEntities().erase(remove_if(i->GetEntities().begin(), i->GetEntities().end(),func),
							 i->GetEntities().end());

		//add new entities
		for( auto it = i->GetEntitiesToBeAdded().begin();it!=i->GetEntitiesToBeAdded().end();it++)
		{
			for( int j = 0; j < it->second;j++)
			{
				std::unique_ptr<Entity> pEntity = move(m_pScene->CreateEntity(it->first));

				i->GetEntities().push_back(std::move(pEntity));
			}
		}

		i->GetEntitiesToBeAdded().clear();
	}

	//moves entites around
	for( auto& i: m_pScene->GetPlanets() )
	{
		for(auto it = i->GetEntities().begin(); it!= i->GetEntities().end();it++)
		{
				m_pPhysics->MoveEntity(*(*it));
		}
	}

	//sort entities by the distance to (0,0,0)
	for( auto& i: m_pScene->GetPlanets() )
	{
		i->SortEntities();
	}

	//after the entities are sorted by distance from the beginning
	//we watch only for two consequent entities in the vector, since they have the chance
	//to be close enough
	for( auto& k: m_pScene->GetPlanets() )
	{
		for(auto it = k->GetEntities().begin(); it!= k->GetEntities().end();it++)
		{
			auto nextEntity = it;
			nextEntity++;

			if( nextEntity != k->GetEntities().end() && m_pPhysics->IsClose(*(*it),*(*nextEntity)) )
			{
				(*it)->DoAction(k,*(*nextEntity));
			}
		}
	}
}