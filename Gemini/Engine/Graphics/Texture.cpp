#include "Texture.h"

Texture::Texture()
{
	//Set ID to invalid value
	id_ = -1;
}

Texture::Texture(int id, Error * error)
{
	//Constructor to Load Texture From ID
	id_ = id;
	if (!LoadTextureParameters(error))
	{
		error->set_errorDescription("Error Loading Image ID: " + std::to_string(id) + ".\n");
	}
}

Texture::Texture(std::string file_path, Error * error)
{
	//Constructor to Load Texture From Disk
	//Loads Image to OpenGL Texture
	//Creates New ID, default format
	//Flags for flipping image vertically and alpha blend
	id_ = SOIL_load_OGL_texture(file_path.c_str(),
		  SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
		  SOIL_FLAG_MULTIPLY_ALPHA |
		  SOIL_FLAG_INVERT_Y);

	//Check that SOIL created valid ID and Load Parameters
	if (!LoadTextureParameters(error))
	{
		error->set_errorDescription("Error Loading Image: " + file_path + ".\n");
	}
}

int Texture::get_id()
{
	return id_;
}

int Texture::get_width()
{
	return width_;
}

int Texture::get_height()
{
	return height_;
}

bool Texture::LoadTextureParameters(Error * error)
{
	//Check for Valid Texture ID
	if (id_ > 0)
	{
		//Set Detail Level - 0 is base level of detail
		int detail_level = 0;
		//Bind the Texture to the target ID
		glBindTexture(GL_TEXTURE_2D, id_);
		//Request Width and Height Parameters from bound texture
		glGetTexLevelParameteriv(GL_TEXTURE_2D, detail_level, GL_TEXTURE_WIDTH,  &width_ );
		glGetTexLevelParameteriv(GL_TEXTURE_2D, detail_level, GL_TEXTURE_HEIGHT, &height_);
		return true;
	}
	error->set_errorDescription("Unable to load texture parameters: invalid texture ID.\n");
	return false;	
}
