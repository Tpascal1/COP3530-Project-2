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

    //make textures for buttons
    sf::Texture normalButton;
    if (!normalButton.loadFromFile("resources/UI_Assets/Button.png")) {
        std::cout << "Error loading image." << std::endl;
    }
    sf::Texture hoverButton;
    if (!hoverButton.loadFromFile("resources/UI_Assets/Button_Hover.png")) {
        std::cout << "Error loading image." << std::endl;
    }

    //Heap Sort Button
    sf::RectangleShape heapRect(sf::Vector2f(400, 200));
    heapRect.setTexture(&normalButton);
    heapRect.setPosition(120, 800);
    sf::FloatRect heapBounds = heapRect.getGlobalBounds();
    //make/style text
    sf::Text heapText;
    heapText.setFont(font);
    heapText.setString("Heap\nSort");
    heapText.setCharacterSize(70);
    heapText.setPosition(250, 810);

    //Merge-Sort Button
    sf::RectangleShape mergeRect(sf::Vector2f(400, 200));
    mergeRect.setTexture(&normalButton);
    mergeRect.setPosition(760, 800);
    sf::FloatRect mergeBounds = mergeRect.getGlobalBounds();
    //make/style text
    sf::Text mergeText;
    mergeText.setFont(font);
    mergeText.setString("Merge\n Sort");
    mergeText.setCharacterSize(70);
    mergeText.setPosition(880,810);

    //Both Button
    sf::RectangleShape bothRect(sf::Vector2f(400, 200));
    bothRect.setTexture(&normalButton);
    bothRect.setPosition(1400, 800);
    sf::FloatRect bothBounds = bothRect.getGlobalBounds();
    //make/style text
    sf::Text bothText;
    bothText.setFont(font);
    bothText.setString("      Run\nComparison");
    bothText.setCharacterSize(70);
    bothText.setPosition(1430,810);


    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Group 42 - Project 2");
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }

            //get mouse position
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

            //check mouse click event
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (heapBounds.contains(static_cast<sf::Vector2f>(mousePos))) {
                        //call heap sort function
                        //this is where we can probably call your guys' function with a certain number, N, of songs given by the user
                        std::cout << "Heap clicked\n";
                    }
                    if (mergeBounds.contains(static_cast<sf::Vector2f>(mousePos))) {
                        //call merge sort function
                        //this is where we can probably call your guys' function with a certain number, N, of songs given by the user
                        std::cout << "Merge clicked\n";

                    }
                    if (bothBounds.contains(static_cast<sf::Vector2f>(mousePos))) {
                        //call both functions 
                        //this is where we can probably call your guys' function with a certain number, N, of songs given by the user
                        std::cout << "Both clicked\n";

                    }
                }
             }
        }

        //get mouse position
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

            //check if mouse is hovering over a button
            if (heapBounds.contains(static_cast<sf::Vector2f>(mousePos))) {
                heapRect.setTexture(&hoverButton); 
            } else {
                heapRect.setTexture(&normalButton);
            }

            if (mergeBounds.contains(static_cast<sf::Vector2f>(mousePos))) {
                mergeRect.setTexture(&hoverButton); 
            } else {
                mergeRect.setTexture(&normalButton);
            }

            if (bothBounds.contains(static_cast<sf::Vector2f>(mousePos))) {
                bothRect.setTexture(&hoverButton);
            } else {
                bothRect.setTexture(&normalButton);
            }
        
        window.clear();
        window.draw(title);
        window.draw(titleText);

        window.draw(heapRect);
        window.draw(heapText);

        window.draw(mergeRect);
        window.draw(mergeText);

        window.draw(bothRect);
        window.draw(bothText);
        window.display();
    }
}