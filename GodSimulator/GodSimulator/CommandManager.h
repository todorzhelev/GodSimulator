#include<iostream>
#include<map>
#include"Scene.h"
#include<sstream>

using namespace std;

class God;

class CommandManager
{
public:

	CommandManager(God* pPlayer,Scene* pScene);

	vector<string> ParseCommand(string command);
	void ExecuteCommand(vector<string> commands);

	vector<string>& GetLastCommand();

private:

	God* m_pPlayer;
	Scene* m_pScene;

	vector<string> m_vLastCommand;
};