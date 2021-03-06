#include"Point3D.h"

Point3D::Point3D():m_fX(0),m_fY(0),m_fZ(0) {}

Point3D::Point3D(double x, double y, double z):m_fX(x),m_fY(y),m_fZ(z) {}

double Point3D::GetX() const
{
	return m_fX;
}

void Point3D::SetX(double x)
{
	m_fX = x;
}

double Point3D::GetY() const
{
	return m_fY;
}

void Point3D::SetY(double y)
{
	m_fY = y;
}

double Point3D::GetZ() const
{
	return m_fZ;
}

void Point3D::SetZ(double z)
{
	m_fZ = z;
}

double Point3D::GetDistance(const Point3D& point1)
{
	return sqrt((point1.GetX()-m_fX)*(point1.GetX()-m_fX)+
				(point1.GetY()-m_fY)*(point1.GetY()-m_fY)+
				(point1.GetZ()-m_fZ)*(point1.GetZ()-m_fZ));
}

double Point3D::GetDistanceToStart()
{
	return sqrt(m_fX*m_fX+m_fY*m_fY+m_fZ*m_fZ);
}