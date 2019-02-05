#ifndef GEMINI_FLAPPER
#define GEMINI_FLAPPER

#include "../Gemini/Engine/Physics/Rigidbody.h"
#include "../Gemini/Engine/Graphics/Sprite.h"
#include "../Gemini/Engine/Math/Rectangle.h"
#include "../Gemini/Engine/IO/Keyboard.h"
#include "../Gemini/Engine/IO/Mouse.h"

class Flapper
{
public:
	Flapper();
	Flapper(Sprite sprite);

	void Update();
	void Render();
	void Flap();
	void Reset();
	
	Sprite & get_sprite();
	Rigidbody & get_rigitbody();

private:
	void HandleInput();

private:
	Sprite sprite_;
	Rigidbody rigidbody_;

	float max_rotation_;
	float min_rotation_;
	float flap_force_;
};

#endif // !GEMINI_FLAPPER
