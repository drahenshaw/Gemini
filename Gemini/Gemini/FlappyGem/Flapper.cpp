#include "Flapper.h"

constexpr float kAbsoluteRotation = 30; 
constexpr float kFlapForce = 750;
static_assert  (kFlapForce > 0, "Dividing by FlapForce = 0");

Flapper::Flapper()
{
	max_rotation_ = 30;
	min_rotation_ = -max_rotation_;
	flap_force_   = kFlapForce;
}

Flapper::Flapper(Sprite sprite) : Flapper()
{
	sprite_ = sprite;

	// Create a new bounding rectangle for the new sprite
	Rectangle bounding_rect = Rectangle();
	Vector3   size_offset   = Vector3(0.8, 0.6, 1); // Change to function?

	// Scale the sprite accordingly
	bounding_rect.set_size(*sprite_.get_size() * *sprite_.get_scale() * size_offset);

	// Construct the rigidbody for the sprite
	rigidbody_ = Rigidbody(0.8f, -10, sprite_.get_rotation(), sprite_.get_position(), sprite_.get_size(), sprite_.get_scale(), Vector3(1), bounding_rect);
}

void Flapper::Update()
{
	HandleInput();
	sprite_.Update();
	rigidbody_.Update();

	float y_velocity = rigidbody_.get_velocity().y_;
	float next_rotation = (max_rotation_ / kFlapForce) * y_velocity;

	// Check this
	sprite_.RotateBy(100);

}

void Flapper::Render()
{
	sprite_.Render();

#if defined _DEBUG
	rigidbody_.Render(Vector3(0, 0, 0));
#endif

}

void Flapper::Flap()
{
	rigidbody_.set_velocity(Vector3(0, kFlapForce, 0));
	sprite_.RotateTo(max_rotation_);
}

void Flapper::Reset()
{
	sprite_.MoveTo(Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
	sprite_.RotateTo(0);
	rigidbody_.set_velocity(Vector3(0, 0, 0));	
}

Sprite & Flapper::get_sprite()
{
	return sprite_;
}

Rigidbody & Flapper::get_rigidbody()
{
	return rigidbody_;
}

void Flapper::HandleInput()
{
	if (Keyboard::KeyDown(GLFW_KEY_SPACE) || Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT))
	{
		Flap();
	}
}


