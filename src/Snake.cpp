//
// Created by Mihai on 30/11/2024.
//

#include "../include/Snake.h"


Snake::Snake(sf::Vector2f position) {
    this->position = position;

    for (int i = 0; i < size; i++) {
        auto shape = createCircle();
        shape.setPosition(position + sf::Vector2f((float) i * linkDistance, 0));
        shapes.push_back(std::make_shared<sf::CircleShape>(shape));
    }
}

void Snake::update(float deltaTime) {
    // Move the snake
    currentVelocity = lerp(currentVelocity, targetVelocity, tAcceleration);
    position += currentVelocity * deltaTime;

    // Update the head (anchor)
    shapes[0]->setPosition(position);

    // Update the rest of the body
    for (int i = 1; i < shapes.size(); i++) {
        auto &shape = shapes[i];
        auto &previousShape = shapes[i - 1];
        // compute vector from previous shape to current shape
        auto direction = shape->getPosition() - previousShape->getPosition();
        // the distance of the direction vector must be max linkDistance
        auto length = std::hypot(direction.x, direction.y);
        if (length > linkDistance) {
            // normalize the direction vector
            direction.x /= length;
            direction.y /= length;
            // set the position of the current shape to the previous shape position + direction * linkDistance
            shape->setPosition(previousShape->getPosition() + direction * linkDistance);
        }
    }
}

void Snake::render(sf::RenderWindow &window) {
    for (int i = 0; i < shapes.size(); i++) {
        window.draw(*shapes[i]);

        if (drawLines && i > 0) {
            // draw a line between the current shape and the previous shape
            auto &shape = shapes[i];
            auto &previousShape = shapes[i - 1];
            // compute length and angle of the line
            auto direction = shape->getPosition() - previousShape->getPosition();
            auto length = std::hypot(direction.x, direction.y) - OUTLINE_THICKNESS;
            auto angle = std::atan2(direction.y, direction.x);
            // draw a rectangle with the length of the line and the thickness of the body
            auto line = createLine();
            line.setSize(sf::Vector2f(length, bodyThickness));
            line.setOrigin(length / 2.f, bodyThickness / 2.f);
            sf::Vector2f midpoint = (shape->getPosition() + previousShape->getPosition()) / 2.f;
            line.setPosition(midpoint);
            line.setRotation(angle * 180.f / (float) M_PI);
            window.draw(line);
        }
    }
}
