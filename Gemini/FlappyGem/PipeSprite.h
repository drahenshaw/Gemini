#ifndef GEMINI_PIPESPRITE
#define GEMINI_PIPESPRITE

#include <iostream>
#include "../Engine/Graphics/Sprite.h"

class PipeSprite : public Sprite
{
public:
	PipeSprite(std::string filePath, Error * error);
	PipeSprite(const Sprite & copy);
	virtual ~PipeSprite() {};
	virtual void Render();
};

#endif
