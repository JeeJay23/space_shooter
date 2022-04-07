#include "Vector.h"

double Vector::magnitude()
{
    // len = sqrt(x^2 + b^2)
    return abs(sqrt(x * x + y * y));
}
