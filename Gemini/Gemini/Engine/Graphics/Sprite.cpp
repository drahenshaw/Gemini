#include "Sprite.h"
#include "../Engine.h"

const int GEMINI_DEFAULT_SPEED = 100;

//Constructs a Textureless Sprite
Sprite::Sprite()
{
	position_ = Vector3(0);
	rotation_ = 0;
	speed_    = GEMINI_DEFAULT_SPEED;
	scale_    = Vector3(1);
	size_     = Vector3(0);
}

//Constructs Sprite with Texture
Sprite::Sprite(std::string file_path, Error * error)
{
	texture_  = Texture(file_path, error);
	position_ = Vector3(0);
	rotation_ = 0;
	speed_    = GEMINI_DEFAULT_SPEED;
	scale_    = Vector3(1);	
	size_     = Vector3((float)texture_.get_width(), (float)texture_.get_height(), 1);
}

//Constructs Sprite with Texture and Starting Position
Sprite::Sprite(std::string file_path, Vector3 position, Error * error)
{
	texture_  = Texture(file_path, error);
	position_ = position;
	rotation_ = 0;
	speed_    = GEMINI_DEFAULT_SPEED;
	scale_    = Vector3(1);
	size_     = Vector3((float)texture_.get_width(), (float)texture_.get_height(), 1);
}

void Sprite::Update()
{
}

void Sprite::Render()
{
	//Enable 2D Texture Operations and Bind those Operations to member texture_
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture_.get_id());
	glLoadIdentity();

	//Matrix Operations are done in reverse order to properly center them
	//TRANSLATE -> ROTATE -> SCALE
	glTranslatef(position_.x_, position_.y_, 0);
	glRotatef(rotation_, 0, 0, 1);
	glScalef(scale_.x_, scale_.y_, 1);

	//Rendering
	glColor4f(1, 1, 1, 1);
	//Begin and End allow for texture coordinates to be updated.
	glBegin(GL_QUADS);
	{
		//Assigning the texture vertices to the corners of the image
		glTexCoord2f(0, 0);		glVertex2i(-texture_.get_width() / 2, -texture_.get_height() / 2);
		glTexCoord2f(1, 0);		glVertex2i( texture_.get_width() / 2, -texture_.get_height() / 2);
		glTexCoord2f(1, 1);		glVertex2i( texture_.get_width() / 2,  texture_.get_height() / 2);
		glTexCoord2f(0, 1);		glVertex2i(-texture_.get_width() / 2,  texture_.get_height() / 2);
	}
	glEnd();

	//Disable 2D Texture Operations
	glDisable(GL_TEXTURE_2D);
}

//Adjust speed by a relative amount
void Sprite::ChangeSpeedBy(float x)
{
	speed_ += x;
}

//Adjust speed to an absolute amount
void Sprite::ChangeSpeedTo(float x)
{
	speed_ = x;
}

//Move to a given position
void Sprite::MoveTo(Vector3 v)
{
	position_ = v;
}

void Sprite::MoveBy(Vector3 v)
{
	position_ = position_ + (v * Engine::get_dT());
}

void Sprite::MoveLeft()
{
	position_ = position_ - Vector3(speed_ * Engine::get_dT(), 0, 0);
}

void Sprite::MoveRight()
{
	position_ = position_ + Vector3(speed_ * Engine::get_dT(), 0, 0);
}

void Sprite::MoveUp()
{
	position_ = position_ + Vector3(0, speed_ * Engine::get_dT(), 0);
}

void Sprite::MoveDown()
{
	position_ = position_ - Vector3(0, speed_ * Engine::get_dT(), 0);
}

void Sprite::RotateTo(float rotation)
{
	rotation_ = rotation;
}

void Sprite::RotateBy(float rotation)
{
	rotation_ = rotation_  + (rotation * Engine::get_dT());
}

void Sprite::setScale(float globalScale)
{
	scale_ = Vector3(globalScale);
}

void Sprite::setScale(Vector3 v)
{
	scale_ = v;
}

void Sprite::FlipHorizontal()
{
	scale_.x_ = -scale_.x_;
}

void Sprite::FlipVertical()
{
	scale_.y_ = -scale_.y_;
}

Vector3 * Sprite::get_position()
{
	return &position_;
}

float * Sprite::get_rotation()
{
	return &rotation_;
}

Vector3 * Sprite::get_scale()
{
	return &scale_;
}

Vector3 * Sprite::get_size()
{
	return &size_;
}
