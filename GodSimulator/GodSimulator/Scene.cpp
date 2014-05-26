#include"Scene.h"


std::vector<Planet*>& Scene::GetPlanets()
{
	return m_Planets;
}

Planet* Scene::GetPlanet(string strPlanetName)
{
	for(auto& i : m_Planets )
	{
		if( !i->GetName().compare(strPlanetName) )
		{
			return i;
		}
	}
}