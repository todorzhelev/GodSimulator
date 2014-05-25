#include<vector>
#include"Entity.h"

#pragma once

class Planet
{
public:
	Planet();

public:

	std::vector<unique_ptr<Entity>> m_vEntities;

};