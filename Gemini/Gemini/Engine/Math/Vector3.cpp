#include "Vector3.h"
#include <math.h>

float Vector3::DotProduct(const Vector3 & a, const Vector3 & b)
{
	return a.x_*b.x_ + a.y_ * b.y_ + a.z_ * b.z_;
}

Vector3 Vector3::VectorProjection(const Vector3 & a, const Vector3 & b)
{
	//Creates a new Vector3 Object that is the result of projecting a onto b
	//Formula: ((a * b) / |b|^2 ) b
	return Vector3(
		  (Vector3::DotProduct(a, b) / ((float)pow(b.x_, 2) + (float)pow(b.y_, 2))) * b.x_,
		  (Vector3::DotProduct(a, b) / ((float)pow(b.x_, 2) + (float)pow(b.y_, 2))) * b.y_, 0);	
}

//Constructs a default Vector3 with |V| = 0
Vector3::Vector3()
{
	x_ = y_ = z_ = 0.0;
}

//Constructs a Vector3 with a global scalar, same magnitude in each direction
Vector3::Vector3(float global)
{
	x_ = y_ = z_ = global;
}

//Constructs a Vector3 with individual x,y,z magnitudes
Vector3::Vector3(float x, float y, float z)
{
	x_ = x;
	y_ = y;
	z_ = z;
}

//Copy Constructor
Vector3::Vector3(const Vector3 & copy)
{
	x_ = copy.x_;
	y_ = copy.y_;
	z_ = copy.z_;

}

//Scale a Vector3 by global factor
Vector3 Vector3::operator*(float global)
{
	Vector3 multiplied;

	multiplied.x_ = x_ * global;
	multiplied.y_ = y_ * global;
	multiplied.z_ = z_ * global;

	return multiplied;
}

//Add one Vector3 to another
Vector3 Vector3::operator+(const Vector3 & rhs)
{
	Vector3 addition;

	addition.x_ = x_ + rhs.x_;
	addition.y_ = y_ + rhs.y_;
	addition.z_ = z_ + rhs.z_;

	return addition;
}

//Subtract one Vector3 from another
Vector3 Vector3::operator-(const Vector3 & rhs)
{
	Vector3 subtraction;

	subtraction.x_ = x_ - rhs.x_;
	subtraction.y_ = y_ - rhs.y_;
	subtraction.z_ = z_ - rhs.z_;
	
	return subtraction;
}

//Multiply one Vector3 magnitude by another
Vector3 Vector3::operator*(const Vector3 & rhs)
{
	Vector3 multiplied;

	multiplied.x_ = x_ * rhs.x_;
	multiplied.y_ = y_ * rhs.y_;
	multiplied.z_ = z_ * rhs.z_;

	return multiplied;
}

//Assign one Vector3 values to another
Vector3 & Vector3::operator=(const Vector3 & rhs)
{
	x_ = rhs.x_;
	y_ = rhs.y_;
	z_ = rhs.z_;
}

//Compare x, y, z values for equivalence
bool Vector3::operator==(const Vector3 & rhs)
{
	return (x_ == rhs.x_ && y_ == rhs.y_ && z_ == rhs.z_);
}

//Compare x, y, z values for difference
bool Vector3::operator!=(const Vector3 & rhs)
{
	return !operator==(rhs);
}
