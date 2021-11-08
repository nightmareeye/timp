#include "iostream"
#include <SFML/Graphics.hpp>
#include <functional>
#include "string"
#include <ctime>

int NewThreadFunc(sf::RenderWindow & window){
    window.setActive();
    sf::Font font;
    if(!font.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-Th.ttf")){
        return 0;
    }
    font.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-B.ttf");
    sf::Text text("",font,20);
    text.setColor(sf::Color::Cyan);
    text.setPosition(10,10);
    sf::String in;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

        }
        text.setString(in.getData());
        window.clear();
        window.draw(text);
        window.display();
    }
    return 0;
}

int main(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "main window");
    sf::Thread mainThread(NewThreadFunc, std::ref(window));
    mainThread.launch();
    mainThread.wait();
    return 0;
}