#include<iostream>
#include"Entity.h"
#include<map>
#include"Planet.h"
#include"God.h"
#include"Scene.h"
#include <sstream>
#include<mutex>

using namespace std;

class CommandManager
{
public:

	CommandManager(God* pPlayer,Scene* pScene);

	vector<string> ParseCommand(string command);
	void ExecuteCommand(vector<string> commands);

	vector<string>& GetLastCommand();

	std::mutex m_mutex;

private:

	

	God* m_pPlayer;
	Scene* m_pScene;

	vector<string> m_vLastCommand;

	//map<string,std::function<void(Planet&)>> m_Commands;

};