#ifndef SPRITE_H
#define SPRITE_H

#include "Texture.h"
#include "../Math/Vector3.h"

class Sprite
{
public:
	Sprite();
	Sprite(std::string path);
	Sprite(std::string path, Vector3 vector);

	void update();

	void render();

	void setSpeed(float x);

	void setPos(Vector3 vector);

	void moveBy(Vector3 vector);

	void moveLeft();

	void moveRight();

	void moveUp();

	void moveDown();

	void setRotationAbsolue(float x);

	void setRotationBy(float x);

	void setScale(float x);

	void setScale(Vector3 vector);

	Texture getTexture();

private:
	Texture _texture;
	Vector3 position;
	float rotation;
	Vector3 scale;
	float speed;
};

#endif // SPRITE_H