#include "Scene.h"

using namespace std;

Scene::Scene()
{
	texture = Texture();
}

Scene::Scene(string path)
{
	texture = Texture(path);
}

void Scene::update()
{
	// add code to continually move.

}

void Scene::render()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture.getID());
	glLoadIdentity();

	glColor4f(1, 1, 1, 1);
	glBegin(GL_QUADS);
	{
		glTexCoord2f(0, 0);		glVertex2f(0, 0);
		glTexCoord2f(1, 0);		glVertex2f(1024, 0);
		glTexCoord2f(1, 1);		glVertex2f(1024, 768);
		glTexCoord2f(0, 1);		glVertex2f(0, 768);
	}
	glEnd();

	glDisable(GL_TEXTURE_2D);
}