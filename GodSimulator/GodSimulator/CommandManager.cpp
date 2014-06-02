#include"CommandManager.h"
#include"God.h"

CommandManager::CommandManager(God* pPlayer,Scene* pScene)
{
	m_pPlayer = pPlayer;
	m_pScene = pScene;
}

//parse the command by empty spaces
vector<string> CommandManager::ParseCommand(string command)
{
	string temp;
	stringstream ss(command); 

	vector<string> parameters;

	while (ss >> temp)
	{
		parameters.push_back(temp);
	}

	m_vLastCommand = parameters;

	return parameters;
}

void CommandManager::ExecuteCommand(vector<string> command)
{
	if( command.size() > 0 )
	{
		if( command.front().find("destroy") != std::string::npos )
		{
			unique_ptr<Planet>& pPlanet = m_pScene->GetPlanet(command[1]);
			if( pPlanet )
			{
				m_pPlayer->DestroyEntirePopulation(*pPlanet);

				cout << "Population destroyed!" << endl << endl;
			}
		}
		else if( command.front().find("list") != std::string::npos)
		{
			for( auto& i : m_pScene->GetPlanets() )
			{
				cout << "Planet " << i->GetName() <<" with " << i->m_vEntities.size() << " population" << endl;
			}
			cout << endl << endl;
		}
		else if( command.front().find("add") != std::string::npos)
		{
			unique_ptr<Planet>& pPlanet = m_pScene->GetPlanet(command[1]);
			EntityType type = m_pScene->ConvertEntityType(command[2]);
			int amount = stoi(command[3]);

			if( pPlanet )
			{
				m_pPlayer->AddEntities(*pPlanet,type,amount);

				cout << "Entities successfuly added!" << endl << endl;
			}
		}
		else if( command.front().find("create") != std::string::npos)
		{
			m_pPlayer->CreatePlanet();
			cout << "Planet successfuly created!" << endl << endl;
		}
		else if( command.front().find("exit") != std::string::npos)
		{
			exit(0);
		}
	}

	m_vLastCommand.clear();
}

vector<string>& CommandManager::GetLastCommand()
{
	return m_vLastCommand;
}