#include "Sprite.h"
#include "../Engine.h"

using namespace std;

Sprite::Sprite()
{
	position = Vector3(0);
	rotation = 0;
	speed = 100;
	scale = Vector3(1, 1, 0);
	_texture = Texture();
}

Sprite::Sprite(string path)
{
	position = Vector3(0);
	rotation = 0;
	speed = 100;
	scale = Vector3(1, 1, 0);
	_texture = Texture(path);
}

Sprite::Sprite(string path, Vector3 vector)
{
	position = vector;
	rotation = 0;
	speed = 100;
	scale = Vector3(1, 1, 0);
	_texture = Texture(path);
}

void Sprite::update()
{

}

void Sprite::render()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _texture.getID());
	glLoadIdentity();

	// Translate, rotate, scale
	glTranslatef(position.x, position.y, 0);
	glRotatef(rotation, 0, 0, 1);
	glScalef(scale.x, scale.y, 1);

	// Render the texture
	glColor4f(1, 1, 1, 1);
	glBegin(GL_QUADS);
	{
		glTexCoord2f(0, 0);		glVertex2f(0, 0);
		glTexCoord2f(1, 0);		glVertex2f(_texture.getWidth(), 0);
		glTexCoord2f(1, 1);		glVertex2f(_texture.getWidth(), _texture.getWidth());
		glTexCoord2f(0, 1);		glVertex2f(0, _texture.getHeight());
	}
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void Sprite::setSpeed(float x)
{
	speed = x;
}

void Sprite::setPos(Vector3 vector)
{
	position = vector;
}

void Sprite::moveBy(Vector3 vector)
{
	position = position + (vector * float(Engine::getDeltaTime()));
}

void Sprite::moveLeft()
{
	position.x -= speed * Engine::getDeltaTime();
}

void Sprite::moveRight()
{
	position.x += speed * Engine::getDeltaTime();
}

void Sprite::moveUp()
{
	position.y += speed * Engine::getDeltaTime();
}

void Sprite::moveDown()
{
	position.y -= speed * Engine::getDeltaTime();
}

Texture Sprite::getTexture()
{
	return _texture;
}

void Sprite::setRotationAbsolue(float x)
{
	rotation = x;
}

void Sprite::setRotationBy(float x)
{
	rotation += x * Engine::getDeltaTime();
}

void Sprite::setScale(float x)
{
	scale.x = x;
	scale.y = x;
}

void Sprite::setScale(Vector3 vector)
{
	scale = vector;
}
