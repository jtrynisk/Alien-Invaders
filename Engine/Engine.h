#ifndef ENGINE_H
#define ENGINE_H

#include <GLFW/glfw3.h>
#include <iostream>

class Engine
{
public:
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;

	Engine(GLFWwindow* window);
	~Engine();

	bool initialize(const char* windowTitle);

	static double getDeltaTime();

	static GLFWwindow& getWindow();

	void update();
	void beginRender();
	void endRender();

private:
	static GLFWwindow* window;

	static double deltaTime;

	double lastTime;
};

#endif // ENGINE_H

