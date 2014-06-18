#include<functional>
#include"Planet.h"
#include"Entity.h"
#include"Animal.h"
#include"Human.h"

#pragma once 

class Scene
{

public:

	std::vector<std::unique_ptr<Planet>>& GetPlanets();

	std::unique_ptr<Planet>& GetPlanet(std::string strPlanetName);

	std::unique_ptr<Entity> CreateEntity(EntityType type);

	//converts from string to EntityType
	EntityType ConvertEntityType(std::string type);

private:


	std::vector<std::unique_ptr<Planet>> m_Planets;
};

extern Scene* m_pScene;