#include<vector>
#include"Entity.h"
#include<map>

#pragma once

class Planet: public Entity
{
public:
	Planet();


public:

	std::map<string,unique_ptr<Entity>> m_vEntities;

};