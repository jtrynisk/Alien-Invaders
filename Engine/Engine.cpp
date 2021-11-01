#include "Engine.h"
#include "IO/Mouse.h"

int Engine::SCREEN_HEIGHT = 768;
int Engine::SCREEN_WIDTH = 1024;
GLFWwindow* Engine::window = nullptr;

Engine::Engine ()
{

}

Engine::~Engine()
{

}

bool Engine::initialize(const char* windowTitle)
{
	if (!glfwInit())
	{
		std::cout << "GLFW failed to init." << std::endl;
	}

	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowTitle, NULL, NULL);
	if (window == nullptr)
	{
		std::cout << "Error creating window" << std::endl;
	}

	// GLFW setup
	glfwMakeContextCurrent(window);
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glfwSwapInterval(1);

	// Mouse callbacks
	glfwSetCursorPosCallback(window, Mouse::mousePosCallback);
	glfwSetMouseButtonCallback(window, Mouse::mouseButtonCallback);
	
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

	return true;
}

void Engine::update()
{
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