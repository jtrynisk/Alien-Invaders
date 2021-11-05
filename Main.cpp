#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Mouse.h"
#include "Engine/IO/Keyboard.h"


int main()
{
	std::cout << "Start your engines" << std::endl;

	Engine engine;

	engine.initialize("Penguin game");

	Sprite sprite = Sprite("Assets/TuxThumbnail_0.png", Vector3(100, 100, 0));

	while (true)
	{
		engine.update();
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

		engine.beginRender();
		sprite.render();
		engine.endRender();
	}

	return 0;
}