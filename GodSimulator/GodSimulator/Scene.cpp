#include"Scene.h"
#include"God.h"

Scene* m_pScene = nullptr;

std::vector<unique_ptr<Planet>>& Scene::GetPlanets()
{
	return m_Planets;
}

unique_ptr<Planet>& Scene::GetPlanet(string strPlanetName)
{
	for(auto& i : m_Planets )
	{
		if( !i->GetName().compare(strPlanetName) )
		{
			return i;
		}
	}

	return unique_ptr<Planet>(nullptr);
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

		case EntityType::GodType :
		{
			unique_ptr<Entity> pNewEntity(new God());
				
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
	else if( type.find("god") != std::string::npos)
	{
		convertedType = EntityType::GodType;
	}

	return convertedType;
}
