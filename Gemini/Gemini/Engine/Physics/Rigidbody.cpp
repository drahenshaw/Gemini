#include "Rigidbody.h"

bool Rigidbody::IsColliding(const Rigidbody & rigidbody_a, const Rigidbody rigidbody_b)
{
	Rectangle rectangle_a = rigidbody_a.bounding_rectangle_;
	Rectangle rectangle_b = rigidbody_b.bounding_rectangle_;

	float a_max = 0.0;
	float a_min = 0.0;
	float b_max = 0.0;
	float b_min = 0.0;

	Vector3 a_upper_left = rectangle_a.get_vertices().upper_left_vertex_ + rigidbody_a.postition_;

	return false;

}

Rigidbody::Rigidbody()
{
}

Rigidbody::Rigidbody(float friction, float gravity, Vector3 position, Vector3 size, Vector3 scale, Vector3 velocity, Rectangle bounds)
{
}

void Rigidbody::Update()
{
}

void Rigidbody::Render(Vector3 color)
{
}

void Rigidbody::AddForce(Vector3 force)
{
}

void Rigidbody::set_velocity(Vector3 velocity)
{
}

Vector3 Rigidbody::get_velocity()
{
	return Vector3();
}
