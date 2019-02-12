#ifndef GEMINI_PIPE
#define GEMINI_PIPE

#include "../Gemini/Engine/Graphics/Sprite.h"
#include "../Gemini/Engine/Physics/Rigidbody.h"
#include "../Gemini/Engine/Math/Vector3.h"

class Pipe
{
public:
	static Sprite * pipe_sprite_;
	void Initialize();

	Pipe(Error * error);
	Pipe(Vector3 position, Error * error);
	
	void Update();
	void Render();

	void MoveTo(Vector3 position);
	void MoveBy(Vector3 offset);
	void UpdatePosition();

	float get_positon_x();
	float get_width();

	Rigidbody get_top_rigidbody();
	Rigidbody get_bottom_rigidbody();

	void set_gap(const float gap);

private:
	float gap_;
	float speed_;
	Vector3 position_;
	Sprite top_sprite_;
	Sprite bottom_sprite_;
	Rigidbody top_rigidbody_;
	Rigidbody bottom_rigidbody_;
};



#endif