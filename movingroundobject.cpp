#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

//using namespace sf;

int main()
{
    sf::RenderWindow window({ 640, 480 }, "Hexagons", sf::Style::Default, sf::ContextSettings(0, 0, 8));
   window.setFramerateLimit(60);

    sf::CircleShape circ;
    circ.setRadius(100);
    circ.setPosition(125, 125);
    circ.setFillColor(sf::Color(50, 50, 50));
    circ.setOrigin(100, 100);
    sf::Clock clc;
    bool drag = false;
    sf::Vector2f click_offs;

    //drawing and handling events
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();   
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mouse_pos = sf::Mouse::getPosition() - window.getPosition();
                    sf::Vector2f circ_pos = circ.getPosition();
                    auto distsq = (mouse_pos.x - circ_pos.x) * (mouse_pos.x - circ_pos.x) + (mouse_pos.y - circ_pos.y) * (mouse_pos.y - circ_pos.y);
                    if (distsq < 10000) {
                        drag = true;
                        click_offs = sf::Vector2f(circ_pos.x - mouse_pos.x, circ_pos.y - mouse_pos.y);
                    }
                    
                }
            }
            if (event.type == sf::Event::MouseButtonReleased) {
                if (drag) {
                    drag = false;
                }
            }

        }

        float elapsed = clc.restart().asMilliseconds();

        sf::Vector2i delta;
        delta.x = 0;
        delta.y = 30;
        sf::Vector2i mouse_pos = sf::Mouse::getPosition() - window.getPosition();
        sf::Vector2f circ_pos = circ.getPosition();
        auto distsq = (mouse_pos.x - circ_pos.x) * (mouse_pos.x - circ_pos.x) + (mouse_pos.y - circ_pos.y) * (mouse_pos.y - circ_pos.y);
        if (distsq < 10000) {
            circ.setFillColor(sf::Color::Green);
        }
        else {
            circ.setFillColor(sf::Color(50, 50, 50));
        }
        if (drag)
        circ.setPosition(sf::Vector2f(mouse_pos) + click_offs);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            circ.move(100 * elapsed /1000 , 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            circ.move( - 100 * elapsed / 1000, 0);
        window.clear(sf::Color::Yellow);

        window.draw(circ);
        window.display();



    }
}
