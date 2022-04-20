#include "Vector.h"

double Vector::magnitude()
{
    return abs(sqrt(x * x + y * y));
}

double Vector::distanceTo(Vector* other)
{
    double distX = abs(x - other->x);
    double distY = abs(y - other->y);
    return sqrt(pow(distX, 2) + pow(distY, 2));
}

double Vector::distanceTo(double x, double y)
{
    double distX = abs(this->x - x);
    double distY = abs(this->y - y);
    return sqrt(pow(distX, 2) + pow(distY, 2));
}
