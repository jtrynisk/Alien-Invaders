#include "Mouse.h"

double Mouse::_xPos = 0;
double Mouse::_yPos = 0;

bool Mouse::_buttons[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::_buttonsUp[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::_buttonsDown[GLFW_MOUSE_BUTTON_LAST] = { 0 };

void Mouse::mousePosCallback(GLFWwindow* window, double x, double y)
{
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);

	_xPos = x;
	_yPos = height - y;
}

void Mouse::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	// Invalid button
	if (button < 0)
	{
		return;
	}
	if (action == GLFW_PRESS && _buttons[button] == false)
	{
		_buttonsDown[button] = true;
		_buttonsDown[button] = false;
	}

	if (action == GLFW_RELEASE && _buttons[button] == true)
	{
		_buttonsDown[button] = false;
		_buttonsUp[button] = true;
	}

	_buttons[button] = action != GLFW_RELEASE;
}

double Mouse::getMouseX()
{
	return _xPos;
}

double Mouse::getMouseY()
{
	return _yPos;
}

bool Mouse::buttonDown(int button)
{
	bool retVal = _buttonsDown[button];
	_buttonsDown[button] = false;
	return retVal;
}

bool Mouse::buttonUp(int button)
{
	bool retVal = _buttonsUp[button];
	_buttonsDown[button] = false;
	return retVal;
}

bool Mouse::buttonPress(int button)
{
	return _buttons[button];
}