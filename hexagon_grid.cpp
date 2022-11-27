#include <SFML/Graphics.hpp>
#include <vector>


int main()
{
    sf::RenderWindow window({ 640, 480 }, "Hexagons", sf::Style::Default, sf::ContextSettings(0, 0, 8));

    // We're simply abusing a `CircleShape` here,
    // since a circle defined by 6 points IS a hexagon!
    sf::CircleShape hexagon(25, 6);
    hexagon.setOutlineColor(sf::Color::Black);
    hexagon.setOutlineThickness(5);
    hexagon.setFillColor(sf::Color::White);
    hexagon.setOrigin(25, 25);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        for (int y = 0; y < 10; ++y) {
            for (int x = 0; x < 10; ++x) {
                // The horizontal/vertical offsets of 50 and 40
                // might feel off, but that's due to the way SFML
                // calculates the circle outline
                hexagon.setPosition((y % 2 ? 75 : 50) + x * 50.f, 50 + y * 40.f);
                hexagon.setFillColor(sf::Color(x * 25, y * 25, 0));
                window.draw(hexagon);
            }
        }
        window.display();
    }
}
