#include"Game.h"

Game::Game()
{
	srand(time(NULL));

	m_pScene = new Scene;

	pPlayer = new God;
}

void Game::Run()
{
	Physics* pPhysics = new Physics;

	Planet* planet = new Planet;

	m_pScene->GetPlanets().push_back(planet);

	pPlayer->InitPopulation(*planet,EntityType::BasicEntity,200);

	map<string,string> closeEntities;

	cout << "Hello, God " << pPlayer->GetName() << endl  << "Your name is already chosen for you and a planet created for you, with entities on it" << endl;

	pPlayer->DestroyEntirePopulation(*planet);

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