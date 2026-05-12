#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "Subject.h"

namespace Arkanoid::Game {
    class Brick :
        public GameObject, public Subject
    {
    public:

        Brick(sf::Vector2f position);
        Brick(sf::Vector2f position, sf::Vector2f size);
        
        virtual bool onHit();

        // Унаследовано через GameObject
        void draw(sf::RenderWindow& window) override;

        ObjectType getType() const override;

        sf::FloatRect getBounds() const override;

        sf::Vector2f getPosition() override;

        void setPosition(sf::Vector2f position) override;

    protected:
        sf::RectangleShape _brick;
    };
}