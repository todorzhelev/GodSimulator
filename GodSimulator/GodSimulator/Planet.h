#include<vector>
#include"Entity.h"

#pragma once

class Planet: public Entity
{
public:
	Planet();


public:

	std::vector<unique_ptr<Entity>> m_vEntities;

};