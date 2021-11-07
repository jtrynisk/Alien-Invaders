#ifndef SCENE_H
#define SCENE_H

#include <GLFW/glfw3.h>
#include <GL/glut.h>

#include "Texture.h"

class Scene
{
public:

	Scene();
	
	Scene(std::string path);

	void update();

	void render();

private:
	Texture texture;
	
};

#endif // SCENE_H