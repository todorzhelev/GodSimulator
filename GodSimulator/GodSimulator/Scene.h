#include<vector>
#include"Planet.h"
#include"Entity.h"
#include"Animal.h"
#include"Human.h"

#pragma once 

class Scene
{

public:

	std::vector<Planet*>& GetPlanets();

	Planet* GetPlanet(string strPlanetName);

	unique_ptr<Entity> CreateEntity(EntityType type);

	//converts from string to EntityType
	EntityType ConvertEntityType(string type);

private:


	std::vector<Planet*> m_Planets;
};

extern Scene* m_pScene;