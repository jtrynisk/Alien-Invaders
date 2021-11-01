#include "Texture.h"

using namespace std;

Texture::Texture() : _id(-1),
					 _height(0),
					 _width(0)
{
}

Texture::Texture(string path)
{
	loadImage(path.c_str());
}

int Texture::getID()
{
	return _id;
}

int Texture::getHeight()
{
	return _height;
}

int Texture::getWidth()
{
	return _width;
}

bool Texture::loadImage(const char* path)
{
	//load and generate texture
	_id = SOIL_load_OGL_texture(path, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MULTIPLY_ALPHA | SOIL_FLAG_INVERT_Y);
	if (_id > 0)
	{

		int mipLevel = 0;
		glBindTexture(GL_TEXTURE_2D, _id);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_WIDTH, &_width);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_HEIGHT, &_height);
		return true;
	}
	else
	{
		std::cout << "Failed to load texture." << std::endl;
	}	
	return false;
}


