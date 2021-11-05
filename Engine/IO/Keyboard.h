#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <GLFW/glfw3.h>

class Keyboard 
{
public:
	static void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);

	static bool keyDown(int key);

	static bool keyUp(int key);

	static bool key(int key);

private:
	static bool _keys[];
	static bool  _keysDown[];
	static bool _keysUp[];
};

#endif // KEYBOARD_H