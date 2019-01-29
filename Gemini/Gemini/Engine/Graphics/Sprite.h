#ifndef GEMINI_SPRITE
#define GEMINI_SPRITE

#include "GLFW/glfw3.h"
#include "Texture.h"
#include "../Math/Vector3.h"
#include "../../Error.h"


class Sprite
{
public:
	Sprite();
	Sprite(std::string file_path, Error * error);
	Sprite(std::string file_path, Vector3 position, Error * error);

	void Update();
	void Render();

	void ChangeSpeedBy(float x);
	void ChangeSpeedTo(float x);

	void MoveTo(Vector3 v);
	void MoveBy(Vector3 v);

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();


	void RotateTo(float rotation);
	void RotateBy(float rotation);

	void setScale(float globalScale);
	void setScale(Vector3 v);

	void FlipHorizontal();
	void FlipVertical();

	Vector3* get_position();
	float*   get_rotation();
	Vector3* get_scale();
	Vector3* get_size();

private:
	Texture texture_;

	float speed_;
	float rotation_;

	Vector3 position_;
	Vector3 scale_;
	Vector3 size_;
};





};

#endif
