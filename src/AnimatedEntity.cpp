//
// Created by Mihai on 30/11/2024.
//

#include "../include/AnimatedEntity.h"

void AnimatedEntity::move(sf::Vector2f direction) {
    targetVelocity = lerp(targetVelocity, direction * speed, 1 - tInertia);
}
