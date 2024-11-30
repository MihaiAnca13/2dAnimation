//
// Created by Mihai on 30/11/2024.
//

#ifndef INC_2DANIMATION_SNAKE_H
#define INC_2DANIMATION_SNAKE_H

#include "AnimatedEntity.h"

class Snake : public AnimatedEntity {
private:
public:
    explicit Snake(sf::Vector2f position);

    void update(float deltaTime) override;

    void render(sf::RenderWindow &window) override;
};


#endif //INC_2DANIMATION_SNAKE_H
