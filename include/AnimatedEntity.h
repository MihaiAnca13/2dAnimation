//
// Created by Mihai on 30/11/2024.
//

#ifndef INC_2DANIMATION_ANIMATEDENTITY_H
#define INC_2DANIMATION_ANIMATEDENTITY_H

#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include "../include/MoveUtilities.h"

class AnimatedEntity {
public:
    sf::Vector2f position, currentVelocity{0.f, 0.f}, targetVelocity{0.f, 0.f};

    bool controlled = false;

    float speed = 350.f, tInertia = 0.2f, tAcceleration = 0.2f;

    virtual void update(float deltaTime) = 0;

    virtual void render(sf::RenderWindow &window) = 0;

    [[maybe_unused]] [[nodiscard]] sf::Vector2f getPosition() const {return position;};

    void move(sf::Vector2f direction);

    virtual ~AnimatedEntity() = default;

protected:
    std::vector<std::shared_ptr<sf::Shape>> shapes;
};


#endif //INC_2DANIMATION_ANIMATEDENTITY_H
