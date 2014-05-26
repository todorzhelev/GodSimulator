#include"Game.h"

Game::Game()
{
	srand(time(NULL));

	m_pScene = new Scene;

	pPlayer = new God;

	m_pCommandManager = new CommandManager(pPlayer,m_pScene);
}

void Game::Run()
{
	Physics* pPhysics = new Physics;

	Planet* planet = new Planet;

	m_pScene->GetPlanets().push_back(planet);

	pPlayer->InitPopulation(*planet,EntityType::BasicEntity,5000);

	map<string,string> closeEntities;

	cout << "Hello, God " << pPlayer->GetName() << endl  << "Your name is already chosen for you and a planet created for you, with entities on it" << endl;

	

	while(true)
	{
		GetCommand();
		

	/*	for( auto& k :planet->m_vEntities )
		{
			pPhysics->MoveEntity(*k);
		}

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
}

void Game::GetCommand()
{
	static bool bShouldShow = true;
	if( bShouldShow )
	{
		bShouldShow = false;
		cout << "You can choose on of the following options:" << endl;
		cout << "Type \" destroy population\" to destroy planet's population" << endl;

		string command;
		getline(cin,command);

		vector<string> commands = m_pCommandManager->ParseCommand(command);
		
		m_pCommandManager->ExecuteCommand(commands);

		bShouldShow = true;
	}
}