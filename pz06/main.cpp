#include "iostream"
#include <SFML/Graphics.hpp>

int main()
{
    int countKeyPressed = 0;
    int countMouseClick = 0;
    std::string keyEnteredMessage("Key Entered:");
    std::string mouseClickMessage("Mouse Click:");

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    sf::Font font;

    if(!font.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-B.ttf")){
        return 0;
    }

    sf::Text textMouse("This is Mouse",font,20);
    textMouse.setColor(sf::Color::Green);
    textMouse.setStyle(sf::Text::Bold);

    sf::Text textKey("This is Key",font,20);
    textKey.setColor(sf::Color::Red);
    textKey.setStyle(sf::Text::Italic);
    textKey.setPosition(0,50);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type){
                case sf::Event::Closed:{
                    window.close();
                    break;
                }
                case sf::Event::MouseButtonReleased:{
                    countMouseClick++;
                    textMouse.setString(mouseClickMessage + std::to_string(countMouseClick));
                    break;
                }
                case sf::Event::TextEntered:{
                    countKeyPressed++;
                    textKey.setString(keyEnteredMessage + std::to_string(countKeyPressed));
                }
            }
        }
        window.clear();
        window.draw(textMouse);
        window.draw(textKey);
        window.display();
    }

    return 0;
}