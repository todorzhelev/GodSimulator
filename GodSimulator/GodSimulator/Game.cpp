#include"Game.h"

Game::Game()
{
	m_pScene = new Scene;

	pPlayer = new God;
}

void Game::Run()
{
	srand(time(NULL));

	int b = 0;

	Physics* pPhysics = new Physics;

	string name;
	cin >> name;

	pPlayer->SetName(name);

	Planet* planet = new Planet;

	m_pScene->GetPlanets().push_back(planet);

	pPlayer->InitPopulation(*planet,EntityType::BasicEntity,200);

	map<string,string> closeEntities;

	while(true)
	{
		for( auto& k :planet->m_vEntities )
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

		}
	}
	
	int a = 10;
}