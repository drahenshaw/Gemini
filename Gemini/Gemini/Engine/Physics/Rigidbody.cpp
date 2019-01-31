#include "Rigidbody.h"

bool Rigidbody::IsColliding(const Rigidbody & rigidbody_a, const Rigidbody rigidbody_b)
{
	// Collision Model being used is the Separating Axis Theorem
	// Start with Bounding Rectangles of each Rigidbody
	Rectangle rectangle_a = rigidbody_a.bounding_rectangle_;
	Rectangle rectangle_b = rigidbody_b.bounding_rectangle_;

	float a_max = 0.0, a_min = 0.0, b_max = 0.0, b_min = 0.0;
	
	Vector3 a_upper_left  = rectangle_a.get_vertices().upper_left_vertex_  + *rigidbody_a.postition_;
	Vector3 a_lower_left  = rectangle_a.get_vertices().lower_left_vertex_  + *rigidbody_a.postition_;
	Vector3 a_upper_right = rectangle_a.get_vertices().upper_right_vertex_ + *rigidbody_a.postition_;
	Vector3 a_lower_right = rectangle_a.get_vertices().lower_right_vertex_ + *rigidbody_a.postition_;
	Vector3 b_upper_left  = rectangle_b.get_vertices().upper_left_vertex_  + *rigidbody_b.postition_;
	Vector3 b_lower_left  = rectangle_b.get_vertices().lower_left_vertex_  + *rigidbody_b.postition_;
	Vector3 b_upper_right = rectangle_b.get_vertices().upper_right_vertex_ + *rigidbody_b.postition_;
	Vector3 b_lower_right = rectangle_b.get_vertices().lower_right_vertex_ + *rigidbody_b.postition_;

	Vector3 axis_one   = a_upper_right - a_upper_left;
	Vector3 axis_two   = a_upper_right - a_lower_right;
	Vector3 axis_three = b_upper_left  - b_lower_left;
	Vector3 axis_four  = b_upper_left  - b_upper_right;

	std::vector<Vector3> axes;
	axes.push_back(axis_one);
	axes.push_back(axis_two);
	axes.push_back(axis_three);
	axes.push_back(axis_four );

	for (unsigned int i = 0; i < axes.size(); ++i)
	{
		Vector3 a_upper_left_projection  = Vector3::VectorProjection(a_upper_left,  axes[i]);
		Vector3 a_lower_left_projection  = Vector3::VectorProjection(a_lower_left,  axes[i]);
		Vector3 a_upper_right_projection = Vector3::VectorProjection(a_upper_right, axes[i]);
		Vector3 a_lower_right_projection = Vector3::VectorProjection(a_lower_right, axes[i]);
		Vector3 b_upper_left_projection  = Vector3::VectorProjection(b_upper_left,  axes[i]);
		Vector3 b_lower_left_projection  = Vector3::VectorProjection(b_lower_left,  axes[i]);
		Vector3 b_upper_right_projection = Vector3::VectorProjection(b_upper_right, axes[i]);
		Vector3 b_lower_right_projection = Vector3::VectorProjection(b_lower_right, axes[i]);

		float a_upper_left_scalar  = Vector3::DotProduct(a_upper_left_projection,  axes[i]);
		float a_lower_left_scalar  = Vector3::DotProduct(a_lower_left_projection,  axes[i]);
		float a_upper_right_scalar = Vector3::DotProduct(a_upper_right_projection, axes[i]);
		float a_lower_right_scalar = Vector3::DotProduct(a_lower_right_projection, axes[i]);
		float b_upper_left_scalar  = Vector3::DotProduct(b_upper_left_projection,  axes[i]);
		float b_lower_left_scalar  = Vector3::DotProduct(b_lower_left_projection,  axes[i]);
		float b_upper_right_scalar = Vector3::DotProduct(b_upper_right_projection, axes[i]);
		float b_lower_right_scalar = Vector3::DotProduct(b_lower_right_projection, axes[i]);

		std::vector<float> a_scalars;
		a_scalars.push_back(a_upper_left_scalar );
		a_scalars.push_back(a_lower_left_scalar );
		a_scalars.push_back(a_upper_right_scalar);
		a_scalars.push_back(a_upper_right_scalar);
		a_max = Math::FindMax(a_scalars);
		a_min = Math::FindMin(a_scalars);

		std::vector<float> b_scalars;
		b_scalars.push_back(b_upper_left_scalar);
		b_scalars.push_back(b_lower_left_scalar);
		b_scalars.push_back(b_upper_right_scalar);
		b_scalars.push_back(b_upper_right_scalar);
		b_max = Math::FindMax(b_scalars);
		b_min = Math::FindMin(b_scalars);

		if (a_max <= b_min && a_min <= b_max) { return false; }			
	}

	return true;
}

Rigidbody::Rigidbody()
{
	friction_ = 1;
	gravity_  = 0;
}

Rigidbody::Rigidbody(float friction, float gravity, float * rotation, Vector3 * position, Vector3 * size, Vector3 * scale, Vector3 * velocity, Rectangle bounds)
{
	friction_  = friction;
	gravity_   = gravity;
	rotation_  = rotation;	
	last_rotation = *rotation;

	postition_ = position;
	size_      = size;
	scale_     = scale;
	velocity_  = velocity;
	bounding_rectangle_ = bounds;
}

void Rigidbody::Update()
{
	velocity_->x_ *= friction_;
	velocity_->y_ -= gravity_;
	
	
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
