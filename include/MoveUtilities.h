//
// Created by Mihai on 30/11/2024.
//

#ifndef INC_2DANIMATION_MOVEUTILITIES_H
#define INC_2DANIMATION_MOVEUTILITIES_H

#include <cmath>

inline float lerpf(float a, float b, float t) {
    return a + t * (b - a);
}

inline sf::Vector2f lerp(sf::Vector2f a, sf::Vector2f b, float t) {
    return {lerpf(a.x, b.x, t), lerpf(a.y, b.y, t)};
}

inline std::tuple<bool, sf::Vector2f> inputHandler() {
    sf::Vector2f movement(0.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        movement.y -= 1.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
        movement.y += 1.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        movement.x -= 1.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        movement.x += 1.f;
    }
    const bool moved = movement.x != 0 || movement.y != 0;

    // normalize the movement vector
    if (moved) {
        const float length = std::hypot(movement.x, movement.y);
        movement.x /= length;
        movement.y /= length;
    }

    return {moved, movement};
}

#endif //INC_2DANIMATION_MOVEUTILITIES_H
