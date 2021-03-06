#include "iostream"
#include <SFML/Graphics.hpp>
#include <functional>
#include "string"
#include <ctime>

int NewThreadFunc(sf::RenderWindow & window) {
    window.setActive();
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-Th.ttf")) {
        return 0;
    }
    font.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-B.ttf");
    sf::Text text("", font, 20);
    text.setColor(sf::Color::Cyan);
    text.setPosition(10, 10);
    sf::String in;
    bool costyl = true;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::TextEntered) {
                if (event.key.code != sf::Keyboard::Backspace) {
                    in.insert(in.getSize(), event.text.unicode);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                    in.insert(in.getSize(), '\n');
                }
                std::string wind = text.getString().toAnsiString();
                if (wind.find("window") != std::string::npos) {
                    if (costyl == true) {
                        window.setActive(false);
                        time_t now = time(0);
                        std::string dt = ctime(&now);
                        std::string nm = "foxmulder-" + dt;
                        sf::RenderWindow win(sf::VideoMode(800, 600), nm);
                        sf::Thread newThread(NewThreadFunc, std::ref(win));
                        newThread.launch();
                        newThread.wait();
                    }
                    costyl = false;
                }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
            {
                if(in.getSize()>0){
                    in.erase(in.getSize()-1, 1);}
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Delete))
            {
                if(in.getSize()>0){
                    in.erase(in.getSize()-1, 1);}
            }
            }
            text.setString(in.getData());
            window.clear();
            window.draw(text);
            window.display();

    }
        return 0;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "main window");
    sf::Thread mainThread(NewThreadFunc, std::ref(window));
    mainThread.launch();
    mainThread.wait();
    return 0;
}