#include<vector>
#include"Entity.h"

#pragma once

class Planet
{
public:
	Planet();

public:

	std::vector<Entity*> m_vEntities;

};