#include "Math.h"

float Math::FindMax(std::vector<float> x)
{
	float max = x[0];

	for (unsigned int i = 0; i < x.size(); ++i)
	{
		if (x[i] > max) { max = x[i]; }
	}
	
	return max;
}

float Math::FindMin(std::vector<float> x)
{
	float min = x[0];

	for (unsigned int i = 0; i < x.size(); ++i)
	{
		if (x[i] < min) { min = x[i]; }
	}

	return min;
}
