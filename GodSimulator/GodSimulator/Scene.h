#include<vector>
#include"Planet.h"

class Scene
{

public:

	std::vector<Planet*>& GetPlanets();
private:


	std::vector<Planet*> m_Planets;
};