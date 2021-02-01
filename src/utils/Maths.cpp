#include "utils/Maths.hpp"
#include "system/Interface.hpp"

int Maths::round (double value)
{
	int floor = (int)value;
	double rem = value - floor;
	return rem >= 0.5 ? floor + 1 : floor;
}
