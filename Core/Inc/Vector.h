#pragma once
#include <cmath>

class Vector
{
public:
	double x;
	double y;

	Vector() : x(0), y(0) {};
	Vector(int x, int y) : x(x), y(y) {};
	double magnitude();
	double distanceTo(Vector*);
	double distanceTo(double, double);
};

