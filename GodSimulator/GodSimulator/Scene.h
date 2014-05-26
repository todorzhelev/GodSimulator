#include<vector>
#include"Planet.h"

#pragma once 

class Scene
{

public:

	std::vector<Planet*>& GetPlanets();

	Planet* GetPlanet(string strPlanetName);

private:


	std::vector<Planet*> m_Planets;
};