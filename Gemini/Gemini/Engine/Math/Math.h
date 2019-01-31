#ifndef GEMINI_MATH
#define GEMINI_MATH

#include "Vector3.h"
#include <vector>

constexpr double kPI = 3.14159;

namespace Math
{
	double ConvertToRadians(double degrees);
	double ConvertToDegrees(double radians);
	Vector3 RotatePoint(Vector3 point, Vector3 pivot, float rotate);
	float FindMax(std::vector<float> x);
	float FindMin(std::vector<float> x);
	float Absolute(float x);
}

#endif 
