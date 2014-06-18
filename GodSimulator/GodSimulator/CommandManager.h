#include"Scene.h"
#include<sstream>

class God;

class CommandManager
{
public:

	CommandManager(God* pPlayer,Scene* pScene);

	std::vector<std::string> ParseCommand(std::string command);
	void ExecuteCommand(std::vector<std::string> commands);

	std::vector<std::string>& GetLastCommand();

private:

	God* m_pPlayer;
	Scene* m_pScene;

	std::vector<std::string> m_vLastCommand;
};