#ifndef GEMINI_RECTANGLE
#define GEMINI_RECTANGLE

#include "Vector3.h"

enum class VertIndex
{
	UPPERLEFT,
	LOWERLEFT,
	UPPERRIGHT,
	LOWERRIGHT,
	COUNT
};

class Rectangle
{
	struct Vertices {
		Vector3 upper_left_vertex_;
		Vector3 lower_left_vertex_;
		Vector3 upper_right_vertex_;
		Vector3 lower_right_vertex_;
	};	

public:
	Rectangle();
	Rectangle(Vector3 size);
	Rectangle(Vector3 size, Vector3 position);
	~Rectangle();

	void MoveBy(Vector3 value);
	void MoveTo(Vector3 location);

	void set_size(Vector3 size);

	const struct Vertices get_vertices();	
	void set_vertices(const Vertices vertices, const VertIndex index, const Vector3 modifier);

private:
	void UpdateVertices();

private:
	
	Vector3 position_;
	Vector3 size_; 
	struct Vertices vertices_;
};

#endif