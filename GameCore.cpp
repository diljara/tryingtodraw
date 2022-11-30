#include "GameCore.h"
#include <iostream>


void GameCore::update(int elapsed) //event handler
{
    sf::Event event;
    bool drag = false;
    window->setFramerateLimit(60);
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) 
                window->close();
        }
            
        /*if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mouse_pos = sf::Mouse::getPosition() - window->getPosition();
               
                

            }
        }*/
        
    }
}

void GameCore::draw()
{
    window->clear();
	


    window->display();
}

void GameCore::start() {
	sf::Clock clc;
	while (window->isOpen()) {
		int elapsed = clc.restart().asMilliseconds();
		update(elapsed);
		draw();
	}
	
}

GameCore::GameCore()
{
    window = new sf::RenderWindow(sf::VideoMode(800, 800), "SFML window");
}
