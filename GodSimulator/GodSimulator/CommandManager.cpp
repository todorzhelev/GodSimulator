#include"CommandManager.h"

CommandManager::CommandManager(God* pPlayer,Scene* pScene)
{
	m_pPlayer = pPlayer;
	m_pScene = pScene;

	//using namespace std::placeholders;

	//m_Commands["destroy"] = std::bind(&God::DestroyEntirePopulation,*m_pPlayer,_1);

}

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
			Planet* pPlanet = m_pScene->GetPlanet(command[1]);
			m_pPlayer->DestroyEntirePopulation(*pPlanet);

		}
		else if( command.front().find("list") != std::string::npos)
		{
			for( auto& i : m_pScene->GetPlanets() )
			{
				cout << "Planet " << i->GetName() <<" with " << i->m_vEntities.size() << " population" << endl;
			}
		}
		else if( command.front().find("init") != std::string::npos)
		{
			Planet* pPlanet = m_pScene->GetPlanet(command[1]);
			EntityType type = m_pScene->ConvertEntityType(command[2]);
			int amount = stoi(command[3]);

			m_pPlayer->InitPopulation(*pPlanet,type,amount);
		}
		else if( command.front().find("exit") != std::string::npos)
		{
			exit(0);
		}
	}

	m_vLastCommand.clear();


	//m_Commands["init"]    = std::bind(&God::InitPopulation,*m_pPlayer,_1,_2,_3);
	//m_Commands["name"] = std::bind(&God::GetName,*m_pPlayer);

}

vector<string>& CommandManager::GetLastCommand()
{
	return m_vLastCommand;
}