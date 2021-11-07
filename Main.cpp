#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Mouse.h"
#include "Engine/IO/Keyboard.h"
#include "Engine/Graphics/Scene.h"


int main()
{
	std::cout << "Start your engines" << std::endl;

	if (!glfwInit())
	{
		std::cout << "GLFW failed to init." << std::endl;
	}

	GLFWwindow* window = glfwCreateWindow(1024, 768, "Alien Invaders!",
		NULL, NULL);
	if (window == nullptr)
	{
		std::cout << "Error creating window" << std::endl;
	};
	Engine engine(window);

	engine.initialize("Penguin game");

	Scene scene("Assets/Starfields/Starfield 1.png");
	Sprite sprite = Sprite("Assets/spaceship.png", Vector3(100, 100, 0));

	while (!glfwWindowShouldClose(window))
	{
		engine.update();
		scene.update();
		sprite.update();

		if (Keyboard::key(GLFW_KEY_W))
		{
			sprite.moveUp();
		}

		if (Keyboard::key(GLFW_KEY_A))
		{
			sprite.moveLeft();
		}

		if (Keyboard::key(GLFW_KEY_S))
		{
			sprite.moveDown();
		}

		if (Keyboard::key(GLFW_KEY_D))
		{
			sprite.moveRight();
		}
		
		if (Keyboard::key(GLFW_KEY_ESCAPE))
		{
			// Pause function here.
		}

		engine.beginRender();
		scene.render();
		sprite.render();
		engine.endRender();
	}

	return 0;
}