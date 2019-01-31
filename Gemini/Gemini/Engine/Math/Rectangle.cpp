#include "Rectangle.h"

// Default Rectangle Constructor
Rectangle::Rectangle()
{
	position_ = Vector3(0);
	size_	  = Vector3(0);
	UpdateVertices();
}

// Delegate Constructor with Size
Rectangle::Rectangle(Vector3 size) : Rectangle()
{
	size_	  = size;
	UpdateVertices();
}

// Delegate Constructor with Size and Position
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

const struct Rectangle::Vertices Rectangle::get_vertices()
{
	return vertices_;
}

void Rectangle::set_vertices(const Vertices vertices, const VertIndex index, const Vector3 modifier)
{
	switch (index)
	{
	case UPPERLEFT:
		vertices_.upper_left_vertex_ = modifier;
		break;

	case LOWERLEFT:
		vertices_.lower_left_vertex_ = modifier;
		break;

	case UPPERRIGHT:
		vertices_.upper_right_vertex_ = modifier;
		break;

	case LOWERRIGHT:
		vertices_.lower_right_vertex_ = modifier;
		break;
	default:
		// Could log error for invalid enum value here?
		break;
	}

}

void Rectangle::UpdateVertices()
{
	// Vertices are found given the center position of the rectangle, add/sub half the size to reach the corners.
	vertices_.upper_left_vertex_  = Vector3(position_.x_ - (size_.x_ / 2), position_.y_ + (size_.y_ / 2), 0);
	vertices_.lower_left_vertex_  = Vector3(position_.x_ - (size_.x_ / 2), position_.y_ - (size_.y_ / 2), 0);
	vertices_.upper_right_vertex_ = Vector3(position_.x_ + (size_.x_ / 2), position_.y_ + (size_.y_ / 2), 0);
	vertices_.lower_right_vertex_ = Vector3(position_.x_ + (size_.x_ / 2), position_.y_ - (size_.y_ / 2), 0);
}
