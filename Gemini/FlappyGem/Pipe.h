#ifndef GEMINI_PIPE
#define GEMINI_PIPE

#include "../Engine/Graphics/Sprite.h"
#include "../Engine/Physics/Rigidbody.h"
#include "../Engine/Math/Vector3.h"
#include "PipeSprite.h"

class Pipe
{
public:
	static Sprite * pipe_sprite_;
	static void Initialize();

	Pipe(Error * error);
	Pipe(Vector3 position, Error * error);
	~Pipe();
	
	void Update();
	void Render();

	bool isOnScreen();
	

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
	Sprite * top_sprite_;
	Sprite * bottom_sprite_;
	Rigidbody top_rigidbody_;
	Rigidbody bottom_rigidbody_;
	static Error * error_;
};



#endif