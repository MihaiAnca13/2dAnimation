#include "include/Display.h"
#include "include/Snake.h"

int main() {
    Display display({1920, 1080, "2D Animation", false, sf::Color(41, 44, 52)});

    auto snake = std::make_unique<Snake>(sf::Vector2f(400, 300));
    snake->controlled = true;

    display.addEntity(std::move(snake));

    display.loop();

    return 0;
}
