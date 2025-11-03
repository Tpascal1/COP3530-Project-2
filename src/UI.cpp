//
// Created by Kaylee on 11/03/2025
//

#include "UI.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void launchUI() {
    //make image into sfml texture
    sf::Texture titleBackground;
    if (!titleBackground.loadFromFile("resources/UI_Assets/Title_Screen_Background.jpg")) {
        std::cout << "Error loading image." << std::endl;
    }

    //make sprite and assign texture from above
    sf::Sprite title;
    title.setTexture(titleBackground);

    //set sprite position
    title.setPosition(0,0);

    //initialize font from assets
    sf::Font font;
    if (!font.loadFromFile("resources/UI_Assets/SuperShiny.ttf")) {
        std::cout << "Error loading font." << std::endl;
    }

    //make/style text
    sf::Text titleText;
    titleText.setFont(font);
    titleText.setString("Optimize Random Song Generation\n                                  Based On Hotness");
    titleText.setCharacterSize(110);
    titleText.setPosition(75,35);

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Group 42 - Project 2");
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();
 
        window.clear();
        window.draw(title);
        window.draw(titleText);
        window.display();
    }
}