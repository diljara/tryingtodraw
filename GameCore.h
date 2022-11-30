#pragma once

#include <SFML/Graphics.hpp>
class GameCore {

	sf::RenderWindow* window;
	void update(int elapsed);
	void draw();

public:
	GameCore();
	void start();

};

