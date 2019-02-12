#ifndef GEMINI_TEXTURE
#define GEMINI_TEXTURE

#include <iostream>
#include <string>
#include "GLFW/glfw3.h"
#include "soil.h"
#include "../Error.h"


class Texture
{
public:
	Texture();
	Texture(int id, Error * error);
	Texture(std::string file_path, Error * error);

	int get_id();
	int get_width();
	int get_height();

private:
	int id_;
	int width_;
	int height_;

private:
	bool LoadTextureParameters(Error * error);
};


#endif

