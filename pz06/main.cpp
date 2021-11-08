#include "iostream"
#include <SFML/Graphics.hpp>
#include <functional>
#include "string"
#include <ctime>

int NewThreadFunc(sf::RenderWindow & window){
    return 0;
}

int main(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "main window");
    sf::Thread mainThread(NewThreadFunc, std::ref(window));
    mainThread.launch();
    mainThread.wait();
    return 0;
}