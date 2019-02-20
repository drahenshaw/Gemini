#include "PipeSprite.h"

PipeSprite::PipeSprite(std::string filePath, Error * error) : Sprite(filePath, error)
{
}

PipeSprite::PipeSprite(const Sprite & copy) : Sprite (copy)
{

}

void PipeSprite::Render()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture_.get_id());
	glLoadIdentity();

	//TRANSLATE -> ROTATE -> SCALE
	glTranslatef(position_.x_, position_.y_, 0);
	glRotatef(rotation_, 0, 0, 1);
	glScalef(scale_.x_, scale_.y_, 1);

	// Rendering
	// Set the Color - Default is 1,1,1,1 which renders original colors
	glColor4f(2, .75, 1, 1);
	glBegin(GL_QUADS);
	{
		glTexCoord2f(0, 0);		glVertex2i(-texture_.get_width() / 2, -texture_.get_height() / 2);
		glTexCoord2f(1, 0);		glVertex2i(texture_.get_width() / 2, -texture_.get_height() / 2);
		glTexCoord2f(1, 1);		glVertex2i(texture_.get_width() / 2, texture_.get_height() / 2);
		glTexCoord2f(0, 1);		glVertex2i(-texture_.get_width() / 2, texture_.get_height() / 2);
	}
	glEnd();

	glDisable(GL_TEXTURE_2D);
}
