#include "Math.h"

double Math::ConvertToRadians(double degrees)
{
	return (degrees * kPI) / 180;
}

double Math::ConvertToDegrees(double radians)
{
	return (radians * 180) / kPI;
}

Vector3 Math::RotatePoint(Vector3 point, Vector3 pivot, float rotate)
{
	double radians_rotation = ConvertToRadians(rotate);
	double s = sin(radians_rotation);
	double c = cos(radians_rotation);

	point = point - pivot;

	float newX = (float)(point.x_ * c - point.y_ * s);
	float newY = (float)(point.x_ * s + point.y_ * c);

	point.x_ = newX + pivot.x_;
	point.y_ = newY + pivot.y_;

	return point;
}

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

float Math::AbsoluteValue(float x)
{
	return (x > 0 ? x : -x);
}
