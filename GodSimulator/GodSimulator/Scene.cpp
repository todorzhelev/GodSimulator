#include"Scene.h"

Scene* m_pScene = nullptr;

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

	return nullptr;
}

unique_ptr<Entity> Scene::CreateEntity(EntityType type)
{
	unique_ptr<Entity> pEntity;

	switch( type )
	{
		case EntityType::BasicEntity :
		{
			unique_ptr<Entity> pNewEntity(new Entity());
				
			pEntity = move(pNewEntity);

			break;
		}

		case EntityType::AnimalType :
		{
			unique_ptr<Entity> pNewEntity(new Animal());
				
			pEntity = move(pNewEntity);

			break;
		}

		case EntityType::HumanType :
		{
			unique_ptr<Entity> pNewEntity(new Human());
				
			pEntity = move(pNewEntity);

			break;
		}
	}

	return pEntity;

}

//converts from string to EntityType
EntityType Scene::ConvertEntityType(string type)
{
	EntityType convertedType;

	if( type.find("entity") != std::string::npos )
	{
		convertedType = EntityType::BasicEntity;
	}
	else if( type.find("animal") != std::string::npos)
	{
		convertedType = EntityType::AnimalType;
	}
	else if( type.find("human") != std::string::npos)
	{
		convertedType = EntityType::HumanType;
	}

	return convertedType;
}
