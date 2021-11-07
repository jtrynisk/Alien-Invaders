#include "Engine.h"
#include "IO/Mouse.h"
#include "IO/Keyboard.h"

int Engine::SCREEN_HEIGHT = 768;
int Engine::SCREEN_WIDTH = 1024;
GLFWwindow* Engine::window = nullptr;
double Engine::deltaTime = 0;

Engine::Engine (GLFWwindow* win)
{
	window = win;
}

Engine::~Engine()
{

}

bool Engine::initialize(const char* windowTitle)
{

	// GLFW setup
	glfwMakeContextCurrent(window);
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glfwSwapInterval(1);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

	// Mouse callbacks
	glfwSetCursorPosCallback(window, Mouse::mousePosCallback);
	glfwSetMouseButtonCallback(window, Mouse::mouseButtonCallback);

	// Keyboard callback
	glfwSetKeyCallback(window, Keyboard::keyCallBack);
	
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	int xPos = (mode->width - SCREEN_HEIGHT) / 2;
	int yPos = (mode->height - SCREEN_HEIGHT) / 2;
	glfwSetWindowPos(window, xPos, yPos);

	//OpenGL setup
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -10, 10);
	glDepthRange(-10, 10);
	glMatrixMode(GL_MODELVIEW);

	// Alpha Blending
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	lastTime = glfwGetTime();

	return true;
}

double Engine::getDeltaTime()
{
	return deltaTime;
}

void Engine::update()
{
	double now = glfwGetTime();
	deltaTime = now - lastTime;
	lastTime = now;
	glfwPollEvents();
}

void Engine::beginRender()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Draw into our window

}

void Engine::endRender()
{
	glfwSwapBuffers(window);
}