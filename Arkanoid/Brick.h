#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

namespace Arkanoid::Game {
    class Brick :
        public GameObject
    {
    public:

        Brick(sf::Vector2f position);

        // Унаследовано через GameObject
        void drow(sf::RenderWindow& window) override;

        ObjectType getType() const override;

        sf::FloatRect getBounds() const override;

        sf::Vector2f getPosition() override;

        void setPosition(sf::Vector2f position) override;

    private:
        sf::RectangleShape _brick;

        
    };
}