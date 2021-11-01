#include "Sprite.h"

using namespace std;

Sprite::Sprite()
{
	_xPos = 0;
	_yPos = 0;
	_texture = Texture();
}

Sprite::Sprite(string path)
{
	_texture = Texture(path);
	_xPos = 0;
	_yPos = 0;
}

Sprite::Sprite(string path, float xPos, float yPos)
{
	_texture = Texture(path);
	_xPos = xPos;
	_yPos = yPos;
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
	glTranslatef(_xPos, _yPos, 0);

	// Render the texture
	glColor4f(1, 1, 1, 1);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);		glVertex2f(0, 0);
	glTexCoord2f(1, 0);		glVertex2f(_texture.getWidth(), 0);
	glTexCoord2f(1, 1);		glVertex2f(_texture.getWidth(), _texture.getWidth());
	glTexCoord2f(0, 1);		glVertex2f(0, _texture.getHeight());
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void Sprite::setPos(float x, float y)
{
	_xPos = x;
	_yPos = y;
}
