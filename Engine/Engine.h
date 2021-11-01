#ifndef ENGINE_H
#define ENGINE_H

#include <GLFW/glfw3.h>
#include <iostream>

class Engine
{
public:
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;

	Engine();
	~Engine();

	bool initialize(const char* windowTitle);

	void update();
	void beginRender();
	void endRender();

private:
	static GLFWwindow* window;
};

#endif // ENGINE_H

