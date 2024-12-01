//
// Created by Mihai on 30/11/2024.
//

#ifndef INC_2DANIMATION_SNAKE_H
#define INC_2DANIMATION_SNAKE_H

#include "AnimatedEntity.h"

class Snake : public AnimatedEntity {
private:
public:
    int size = 15;
    std::vector<float> bodySizes{15.f};
    float linkDistance = 45.f;
    float bodyThickness = 25.f;
    bool drawLines = false;

    explicit Snake(sf::Vector2f position);

    void update(float deltaTime) override;

    void render(sf::RenderWindow &window) override;
};


#endif //INC_2DANIMATION_SNAKE_H
