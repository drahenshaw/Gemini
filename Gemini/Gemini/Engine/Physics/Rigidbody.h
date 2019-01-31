#ifndef GEMINI_ENGINE
#define GEMINI_ENGINE

#include "../Math/Math.h"
#include "../Math/Rectangle.h"
#include "../Math/Vector3.h"
#include "../Engine.h"
#include <vector>

class Rigidbody
{
public:
	static bool IsColliding(const Rigidbody & rigidbody_a, const Rigidbody rigidbody_b);

	Rigidbody();
	Rigidbody(float friction, float gravity, float * rotation, Vector3 * position, Vector3 * size, Vector3 * scale, Vector3 * velocity, Rectangle bounds);

	void Update();
	void Render(Vector3 color);

	void AddForce(Vector3 force);

	void    set_velocity(Vector3 velocity);
	Vector3 get_velocity();

private:

	float friction_;
	float gravity_;
	float * rotation_;
	float last_rotation;

	Vector3 * postition_;
	Vector3 * size_;
	Vector3 * scale_;
	Vector3 * velocity_;	

	Rectangle bounding_rectangle_;
};



#endif