#include "Rigidbody.h"

bool Rigidbody::IsColliding(const Rigidbody & rigidbody_a, const Rigidbody & rigidbody_b)
{
	// Collision Model being used is the Separating Axis Theorem
	// Start with Bounding Rectangles of each Rigidbody
	Rectangle rectangle_a = rigidbody_a.bounding_rectangle_;
	Rectangle rectangle_b = rigidbody_b.bounding_rectangle_;

	float a_max = 0.0, a_min = 0.0, b_max = 0.0, b_min = 0.0;
	
	Vector3 a_upper_left  = rectangle_a.get_vertices().upper_left_vertex_  + *rigidbody_a.position_;
	Vector3 a_lower_left  = rectangle_a.get_vertices().lower_left_vertex_  + *rigidbody_a.position_;
	Vector3 a_upper_right = rectangle_a.get_vertices().upper_right_vertex_ + *rigidbody_a.position_;
	Vector3 a_lower_right = rectangle_a.get_vertices().lower_right_vertex_ + *rigidbody_a.position_;
	Vector3 b_upper_left  = rectangle_b.get_vertices().upper_left_vertex_  + *rigidbody_b.position_;
	Vector3 b_lower_left  = rectangle_b.get_vertices().lower_left_vertex_  + *rigidbody_b.position_;
	Vector3 b_upper_right = rectangle_b.get_vertices().upper_right_vertex_ + *rigidbody_b.position_;
	Vector3 b_lower_right = rectangle_b.get_vertices().lower_right_vertex_ + *rigidbody_b.position_;

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

Rigidbody::Rigidbody(float friction, float gravity, float * rotation, Vector3 * position, Vector3 * size, Vector3 * scale, Vector3 velocity, Rectangle bounds)
{
	friction_  = friction;
	gravity_   = gravity;
	rotation_  = rotation;	
	last_rotation_ = *rotation;

	position_ = position;
	size_      = size;
	scale_     = scale;
	velocity_  = velocity;
	bounding_rectangle_ = bounds;
}

void Rigidbody::Update()
{
	velocity_.x_ *= friction_;
	velocity_.y_ += gravity_;

	*position_ = *position_ + (velocity_ * Engine::get_dT());

	if (last_rotation_ != *rotation_)
	{
		bounding_rectangle_.set_vertices(bounding_rectangle_.get_vertices(), VertIndex::UPPERLEFT,  Math::RotatePoint(bounding_rectangle_.get_vertices().upper_left_vertex_,  Vector3(0), *rotation_ - last_rotation_));
		bounding_rectangle_.set_vertices(bounding_rectangle_.get_vertices(), VertIndex::LOWERLEFT,  Math::RotatePoint(bounding_rectangle_.get_vertices().lower_left_vertex_,  Vector3(0), *rotation_ - last_rotation_));
		bounding_rectangle_.set_vertices(bounding_rectangle_.get_vertices(), VertIndex::UPPERRIGHT, Math::RotatePoint(bounding_rectangle_.get_vertices().upper_right_vertex_, Vector3(0), *rotation_ - last_rotation_));
		bounding_rectangle_.set_vertices(bounding_rectangle_.get_vertices(), VertIndex::LOWERRIGHT, Math::RotatePoint(bounding_rectangle_.get_vertices().lower_right_vertex_, Vector3(0), *rotation_ - last_rotation_));
		last_rotation_ = *rotation_;
		
	}

	//if (last_rotation_ != *rotation_)
	//{
	//	bounding_rectangle_.set_vertices(bounding_rectangle_.get_vertices().upper_left_vertex_  = Math::RotatePoint(bounding_rectangle_.get_vertices().upper_left_vertex_,  Vector3(0), *rotation_ - last_rotation_));
	//	bounding_rectangle_.set_vertices(bounding_rectangle_.get_vertices().lower_left_vertex_  = Math::RotatePoint(bounding_rectangle_.get_vertices().lower_left_vertex_,  Vector3(0), *rotation_ - last_rotation_));
	//	bounding_rectangle_.set_vertices(bounding_rectangle_.get_vertices().upper_right_vertex_ = Math::RotatePoint(bounding_rectangle_.get_vertices().upper_right_vertex_, Vector3(0), *rotation_ - last_rotation_));
	//	bounding_rectangle_.set_vertices(bounding_rectangle_.get_vertices().lower_right_vertex_ = Math::RotatePoint(bounding_rectangle_.get_vertices().lower_right_vertex_, Vector3(0), *rotation_ - last_rotation_));
	//	last_rotation_ = *rotation_;
	//}
}

void Rigidbody::Render(Vector3 color)
{
	glLoadIdentity();
	glTranslatef(position_->x_, position_->y_, position_->z_);
	glColor4f(color.x_, color.y_, color.z_, 1);

	glBegin(GL_LINES);
	{
		// Draw Rigidbody Bottom Side		
		glVertex2f(bounding_rectangle_.get_vertices().lower_left_vertex_.x_,  bounding_rectangle_.get_vertices().lower_left_vertex_.y_ );
		glVertex2f(bounding_rectangle_.get_vertices().lower_right_vertex_.x_, bounding_rectangle_.get_vertices().lower_right_vertex_.y_);

		// Draw Rigidbody Right Side
		glVertex2f(bounding_rectangle_.get_vertices().lower_right_vertex_.x_, bounding_rectangle_.get_vertices().lower_right_vertex_.y_);
		glVertex2f(bounding_rectangle_.get_vertices().upper_right_vertex_.x_, bounding_rectangle_.get_vertices().upper_right_vertex_.y_);

		// Draw Rigidbody Top Side
		glVertex2f(bounding_rectangle_.get_vertices().upper_right_vertex_.x_, bounding_rectangle_.get_vertices().upper_right_vertex_.y_);
		glVertex2f(bounding_rectangle_.get_vertices().upper_left_vertex_.x_,  bounding_rectangle_.get_vertices().upper_left_vertex_.y_ );

		// Draw Rigidbody Left Side
		glVertex2f(bounding_rectangle_.get_vertices().upper_left_vertex_.x_,  bounding_rectangle_.get_vertices().upper_left_vertex_.y_);
		glVertex2f(bounding_rectangle_.get_vertices().lower_left_vertex_.x_,  bounding_rectangle_.get_vertices().lower_left_vertex_.y_);

	}
	glEnd();
}

void Rigidbody::AddForce(Vector3 force)
{
	velocity_ += force;
}

void Rigidbody::set_velocity(Vector3 velocity)
{
	velocity_ = velocity;
}

Vector3 Rigidbody::get_velocity()
{
	return velocity_;
}
