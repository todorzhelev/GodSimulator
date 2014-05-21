#pragma once

class Point3D
{

public:

	Point3D();
	Point3D(double x, double y, double z);

	double GetX();
	void SetX(double x);

	double GetY();
	void SetY(double y);

	double GetZ();
	void SetZ(double z);


private:
	double m_fX,m_fY,m_fZ;
};