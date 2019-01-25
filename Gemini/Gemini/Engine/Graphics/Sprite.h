#ifndef GEMINI_SPRITE
#define GEMINI_SPRITE

#include "GLFW/glfw3.h"
#include "Texture.h"
#include "../../Error.h"


class Sprite
{
public:
	Sprite();
	Sprite(std::string file_path, Error * error);
	Sprite(std::string file_path, /*Vector 3 position,*/ Error * error);

	void Update();
	void Render();

	void SpeedBy(float x);
	void SpeedTo(float x);

	void MoveTo(Vector3 v);
	void MoveBy(Vector3 v);

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();


	void RotateTo(float rot);
	void RotateBy(float rot);

	void setScale(float globalScale);
	void setScale(Vector3 v);

	void FlipHorizontal();
	void FlipVertical();

	Vector3* getPos();
	float*   getRot();
	Vector3* getScale();
	Vector3* getSize();

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
