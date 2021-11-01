#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Mouse.h"


int main()
{
	std::cout << "Start your engines" << std::endl;

	Engine engine;

	engine.initialize("Penguin game");

	Sprite sprite = Sprite("Assets/TuxThumbnail_0.png", 100, 100);

	while (true)
	{
		engine.update();
		sprite.update();

		sprite.setPos((float)Mouse::getMouseX(), (float)Mouse::getMouseY());

		engine.beginRender();
		sprite.render();
		engine.endRender();
	}

	return 0;
}