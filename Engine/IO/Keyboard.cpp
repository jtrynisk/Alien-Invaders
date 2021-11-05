#include "Keyboard.h"

bool Keyboard::_keys[GLFW_KEY_LAST] = { 0 };
bool Keyboard::_keysDown[GLFW_KEY_LAST] = { 0 };
bool Keyboard::_keysUp[GLFW_KEY_LAST] = { 0 };

void Keyboard::keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key < 0)
	{
		return;
	}
	if (action != GLFW_RELEASE && _keys[key] == false)
	{
		_keysDown[key] = true;
		_keysUp[key] = false;
	}

	if (action == GLFW_RELEASE && _keys[key] == true)
	{
		_keysDown[key] = false;
		_keysUp[key] = true;
	}

	_keys[key] = action != GLFW_RELEASE;
}

bool Keyboard::keyDown(int key)
{
	bool retVal = _keysDown[key];
	_keysDown[key] = false;
	return retVal;
}

bool Keyboard::keyUp(int key)
{
	bool retVal = _keysUp[key];
	_keysUp[key] = false;
	return retVal;
}

bool Keyboard::key(int key)
{
	return _keys[key];
}