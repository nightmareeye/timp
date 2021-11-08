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


    return 0;
}

int main(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "main window");
    sf::Thread mainThread(NewThreadFunc, std::ref(window));
    mainThread.launch();
    mainThread.wait();
    return 0;
}