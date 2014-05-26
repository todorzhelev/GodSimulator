#include<iostream>
#include<functional>
#include"Entity.h"
#include<map>
#include"Planet.h"
#include"God.h"
#include"Scene.h"
#include <sstream>

using namespace std;

class CommandManager
{
public:

	CommandManager(God* pPlayer,Scene* pScene);

	vector<string> ParseCommand(string command);
	void ExecuteCommand(vector<string> commands);

private:

	God* m_pPlayer;
	Scene* m_pScene;

	//map<string,std::function<void(Planet&)>> m_Commands;

};