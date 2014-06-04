#include<vector>
#include"Entity.h"
#include<map>
#include<functional>
#include<algorithm>

using namespace placeholders;

#pragma once

class Planet: public Entity
{
public:

	Planet();

	void SortEntities();

	bool EntitesComparator(const unique_ptr<Entity>& ent1,const unique_ptr<Entity>& ent2);

public:

	vector<unique_ptr<Entity>> m_vEntities;
	map<EntityType, int> m_EntitiesToBeAdded;
};