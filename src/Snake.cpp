//
// Created by Mihai on 30/11/2024.
//

#include "../include/Snake.h"


Snake::Snake(sf::Vector2f position) {
    this->position = position;

    sf::CircleShape shape(5.f);
    shape.setFillColor(sf::Color::Transparent);
    shape.setPosition(position);
    shape.setPointCount(40);
    // set a 10-pixel wide outline
    shape.setOutlineThickness(10.f);
    shape.setOutlineColor(sf::Color::White);

    shapes.push_back(std::make_shared<sf::CircleShape>(shape));
}

void Snake::update(float deltaTime) {
    // Move the snake
    currentVelocity = lerp(currentVelocity, targetVelocity, tAcceleration);
    position += currentVelocity * deltaTime;

    // Update the shape
    shapes[0]->setPosition(position);
}

void Snake::render(sf::RenderWindow &window) {
    for (const auto &shape: shapes) {
        window.draw(*shape);
    }
}
