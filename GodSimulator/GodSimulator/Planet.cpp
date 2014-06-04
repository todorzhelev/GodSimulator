#include"Planet.h"

Planet::Planet():Entity()
{

}

bool Planet::EntitesComparator(const unique_ptr<Entity>& ent1,const unique_ptr<Entity>& ent2)
{
	return ent1->GetPosition().GetDistanceToStart() > ent2->GetPosition().GetDistanceToStart();
}

void Planet::SortEntities()
{
	using namespace placeholders;
	sort(m_vEntities.begin(),m_vEntities.end(),std::bind(&Planet::EntitesComparator,this,_1,_2));
}