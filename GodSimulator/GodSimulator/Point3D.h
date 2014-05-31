#include<cmath>
#pragma once

class Point3D
{

public:

	Point3D();
	Point3D(double x, double y, double z);

	double GetX() const;
	void SetX(double x);

	double GetY() const;
	void SetY(double y);

	double GetZ() const;
	void SetZ(double z);

	double GetDistance(const Point3D& point1);
	double GetDistanceToStart();


private:
	double m_fX,m_fY,m_fZ;
};