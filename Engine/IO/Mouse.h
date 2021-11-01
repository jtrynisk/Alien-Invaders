#ifndef MOUSE_H
#define MOUSE_H

#include <GLFW/glfw3.h>

class Mouse
{
public:
	static void mousePosCallback(GLFWwindow* window, double x, double y);

	static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

	static double getMouseX();

	static double getMouseY();

	static bool buttonDown(int button);

	static bool buttonUp(int button);

	static bool buttonPress(int button);

private:
	static double _xPos;
	static double _yPos;

	static bool _buttons[];
	static bool _buttonsDown[];
	static bool _buttonsUp[];
};

#endif // MOUSE_H
