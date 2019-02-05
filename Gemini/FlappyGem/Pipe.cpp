#include "Pipe.h"

Sprite * Pipe::pipe_sprite_ = nullptr;

void Pipe::Initialize()
{
	pipe_sprite_ = new Sprite();
	pipe_sprite_->setScale(0.1f);
}

Pipe::Pipe(Error * error)
{
	if (!pipe_sprite_)
	{
		error->set_errorDescription("Trying to instantiate Pipe without initializing.\n");
		error->set_errorStatus(Error::kInitializationError);
		return;
	}

	top_sprite_    = Sprite(*pipe_sprite_);
	bottom_sprite_ = Sprite(*pipe_sprite_);

	gap_ = 500;
	speed_ = 200;
}

Pipe::Pipe(Vector3 position, Error * error) : Pipe(error)
{
	if (!pipe_sprite_)
	{
		return;
	}

	position_ = position + Vector3(get_width(), 0, 0);
	UpdatePosition();
	top_sprite_.FlipVertical();

	Rectangle top_bounds = Rectangle();
	top_bounds.set_size(Vector3(Math::AbsoluteValue(top_sprite_.get_size()->x_ * top_sprite_.get_scale()->x_), Math::AbsoluteValue(top_sprite_.get_size()->y_* top_sprite_.get_scale()->y_), 0));
	top_rigidbody_ = Rigidbody(0, 1, top_sprite_.get_rotation(), top_sprite_.get_position(), top_sprite_.get_size(), top_sprite_.get_scale(), 1, top_bounds);

	Rectangle bottom_bounds = Rectangle();
	bottom_bounds.set_size(Vector3(Math::AbsoluteValue(bottom_sprite_.get_size()->x_ * bottom_sprite_.get_scale()->x_), Math::AbsoluteValue(bottom_sprite_.get_size()->y_* bottom_sprite_.get_scale()->y_), 0));
	bottom_rigidbody_ = Rigidbody(0, 1, bottom_sprite_.get_rotation(), bottom_sprite_.get_position(), bottom_sprite_.get_size(), bottom_sprite_.get_scale(), 1, bottom_bounds);

	top_rigidbody_   .AddForce(Vector3(-speed_, 0, 0));
	bottom_rigidbody_.AddForce(Vector3(-speed_, 0, 0));
}

void Pipe::Update()
{
	top_rigidbody_   .Update();
	bottom_rigidbody_.Update();
}

void Pipe::Render()
{
	top_sprite_   .Render();
	bottom_sprite_.Render();

#if defined _DEBUG
	top_rigidbody_   .Render(Vector3(0, 0, 0));
	bottom_rigidbody_.Render(Vector3(0, 0, 0));
#endif

}

void Pipe::MoveTo(Vector3 position)
{
	position_ = position;
	UpdatePosition();
}

void Pipe::MoveBy(Vector3 offset)
{
	position_ += offset;
	UpdatePosition();
}

void Pipe::UpdatePosition()
{
	Vector3 top_position  = position_;
	top_position.y_ += (gap_ / 2) + Math::AbsoluteValue(top_sprite_.get_size()->y_ * top_sprite_.get_scale()->y_ / 2);
	top_sprite_.MoveTo(top_position);

	Vector3 bot_position = position_;
	bot_position.y_ -= (gap_ / 2) + Math::AbsoluteValue(top_sprite_.get_size()->y_ * top_sprite_.get_scale()->y_ / 2);
	bottom_sprite_.MoveTo(bot_position);	
}

float Pipe::get_positon_x()
{
	return top_sprite_.get_position()->x_;
}

float Pipe::get_width()
{
	return (top_sprite_.get_size()->x_ * top_sprite_.get_scale()->x_);
}

Rigidbody Pipe::get_top_rigidbody()
{
	return top_rigidbody_;
}

Rigidbody Pipe::get_bottom_rigidbody()
{
	return bottom_rigidbody_;
}
