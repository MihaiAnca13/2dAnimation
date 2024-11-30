//
// Created by Mihai on 28/11/2024.
//

#include "../include/Display.h"
#include "../include/AnimatedEntity.h"


Display::Display(Settings settings) {
    this->settings = settings;
    auto style = settings.fullscreen ? sf::Style::Fullscreen : sf::Style::Titlebar | sf::Style::Close;

    sf::ContextSettings contextSettings;
    contextSettings.antialiasingLevel = 8;

    window.create(sf::VideoMode(settings.width, settings.height), settings.title, style, contextSettings);
//    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
}

void Display::loop() {
    sf::Clock clock;

    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();

        // Handle events
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        for (auto &entity: entities) {
            if (entity->controlled) {
                auto [moved, direction] = inputHandler();
                entity->move(direction);
            }
        }

        // Update all entities
        for (auto &entity: entities) {
            entity->update(deltaTime);
        }

        // Clear the window
        window.clear(settings.color);

        // Draw all entities
        for (auto &entity: entities) {
            entity->render(window);
        }

        window.display();
    }
}

void Display::addEntity(std::unique_ptr<AnimatedEntity> entity) {
    entities.push_back(std::move(entity));
}