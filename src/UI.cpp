//
// Created by Kaylee on 11/03/2025
//

#include "UI.h"
#include <SFML/Graphics.hpp>

void launchUI() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Test");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        window.clear();
        window.draw(shape);
        window.display();
    }
}