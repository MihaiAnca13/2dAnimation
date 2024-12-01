//
// Created by Mihai on 30/11/2024.
//

#ifndef INC_2DANIMATION_DRAWUTILITIES_H
#define INC_2DANIMATION_DRAWUTILITIES_H

#include <SFML/Graphics.hpp>

#define OUTLINE_THICKNESS 10.f

inline sf::CircleShape createCircle() {
    sf::CircleShape shape(5.f);
    shape.setFillColor(sf::Color::Transparent);
    shape.setPointCount(40);
    shape.setPosition(0, 0);
    shape.setOrigin(5.f, 5.f);
    // set a 10-pixel wide outline
    shape.setOutlineThickness(OUTLINE_THICKNESS);
    shape.setOutlineColor(sf::Color::White);
    return shape;
}

inline sf::RectangleShape createLine() {
    sf::RectangleShape shape(sf::Vector2f(100, 5));
    shape.setFillColor(sf::Color::White);
    return shape;
}

#endif //INC_2DANIMATION_DRAWUTILITIES_H
