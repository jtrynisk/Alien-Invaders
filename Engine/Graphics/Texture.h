#ifndef TEXTURE_H
#define TEXTURE_H

#include <GLFW/glfw3.h>
#include "SOIL/src/SOIL.h"

#include <iostream>

#include <string>

class Texture
{
public:
	Texture();
	Texture(std::string path);

	int getID();
	int getWidth();
	int getHeight();

private:
	bool loadImage(const char* path);

	int _id;
	int _width;
	int _height;
};

#endif // TEXTURE_H