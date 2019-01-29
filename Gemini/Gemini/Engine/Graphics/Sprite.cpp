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
		glTexCoord2f(0, 0);		glVertex2i(-texture_.get_width() / 2, -texture_.get_height() / 2);
		glTexCoord2f(1, 0);		glVertex2i( texture_.get_width() / 2, -texture_.get_height() / 2);
		glTexCoord2f(1, 1);		glVertex2i( texture_.get_width() / 2,  texture_.get_height() / 2);
		glTexCoord2f(0, 1);		glVertex2i(-texture_.get_width() / 2,  texture_.get_height() / 2);
	}
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void Sprite::ChangeSpeedBy(float x)
{
}

void Sprite::ChangeSpeedTo(float x)
{
}

void Sprite::MoveTo(Vector3 v)
{
}

void Sprite::MoveBy(Vector3 v)
{
}

void Sprite::MoveLeft()
{
}

void Sprite::MoveRight()
{
}

void Sprite::MoveUp()
{
}

void Sprite::MoveDown()
{
}

void Sprite::RotateTo(float rot)
{
}

void Sprite::RotateBy(float rot)
{
}

void Sprite::setScale(float globalScale)
{
}

void Sprite::setScale(Vector3 v)
{
}

void Sprite::FlipHorizontal()
{
}

void Sprite::FlipVertical()
{
}

Vector3 * Sprite::get_position()
{
	return nullptr;
}

float * Sprite::get_rotation()
{
	return nullptr;
}

Vector3 * Sprite::get_scale()
{
	return nullptr;
}

Vector3 * Sprite::get_size()
{
	return nullptr;
}
