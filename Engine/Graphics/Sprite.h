#ifndef SPRITE_H
#define SPRITE_H

#include "Texture.h"

class Sprite
{
public:
	Sprite();
	Sprite(std::string path);
	Sprite(std::string path, float xPos, float yPos);

	void update();
	void render();

	void setPos(float x, float y);

private:
	Texture _texture;
	float _xPos;
	float _yPos;
};

#endif // SPRITE_H