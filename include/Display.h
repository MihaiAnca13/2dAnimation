//
// Created by Mihai on 28/11/2024.
//

#ifndef INC_2DANIMATION_DISPLAY_H
#define INC_2DANIMATION_DISPLAY_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>

class AnimatedEntity;

struct Settings {
    int width;
    int height;
    const char* title;
    bool fullscreen;
    sf::Color color;
};

class Display {
public:
    explicit Display(Settings settings);
    void loop();
    void addEntity(std::unique_ptr<AnimatedEntity> entity);

private:
    Settings settings;
    sf::RenderWindow window;
    std::vector<std::unique_ptr<AnimatedEntity>> entities;
};


#endif //INC_2DANIMATION_DISPLAY_H
