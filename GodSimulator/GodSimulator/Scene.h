#include<functional>
#include"Planet.h"
#include"Entity.h"
#include"Animal.h"
#include"Human.h"


#pragma once 

class Scene
{

public:

	std::vector<unique_ptr<Planet>>& GetPlanets();

	unique_ptr<Planet>& GetPlanet(string strPlanetName);

	unique_ptr<Entity> CreateEntity(EntityType type);

	//converts from string to EntityType
	EntityType ConvertEntityType(string type);

private:


	std::vector<unique_ptr<Planet>> m_Planets;
};

extern Scene* m_pScene;