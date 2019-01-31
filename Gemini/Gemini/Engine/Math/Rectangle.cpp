#include "Rectangle.h"

Rectangle::Rectangle()
{
	position_ = Vector3(0);
	size_	  = Vector3(0);
	UpdateVertices();
}

Rectangle::Rectangle(Vector3 size) : Rectangle()
{
	size_	  = size;
	UpdateVertices();
}

Rectangle::Rectangle(Vector3 size, Vector3 position) : Rectangle(size)
{
	position_ = position;
	UpdateVertices();
}

Rectangle::~Rectangle()
{

}

void Rectangle::MoveBy(Vector3 value)
{
	position_ += value;
}

void Rectangle::MoveTo(Vector3 location)
{
	position_ = location;
}

void Rectangle::set_size(Vector3 size)
{
	size_ = size;
}

void Rectangle::UpdateVertices()
{
	upper_left_vertex_  = Vector3(position_.x_ - (size_.x_ / 2), position_.y_ + (size_.y_ / 2), 0);
	lower_left_vertex_  = Vector3(position_.x_ - (size_.x_ / 2), position_.y_ - (size_.y_ / 2), 0);
	upper_right_vertex_ = Vector3(position_.x_ + (size_.x_ / 2), position_.y_ + (size_.y_ / 2), 0);
	upper_right_vertex_ = Vector3(position_.x_ + (size_.x_ / 2), position_.y_ - (size_.y_ / 2), 0);
}
