#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "Subject.h"
#include "BrickType.h"
#include "BrickData.h"

namespace Arkanoid::Game {
    class Brick :
        public GameObject, public Subject
    {
    public:

        Brick(sf::Vector2f position);
        Brick(sf::Vector2f position, sf::Vector2f size);
        
        virtual bool onHit();
        virtual int getHP();
        virtual BrickData getData();

        // Унаследовано через GameObject
        void draw(sf::RenderWindow& window) override;

        ObjectType getType() const override;
        virtual BrickType getBrickType() const;

        sf::FloatRect getBounds() const override;

        sf::Vector2f getPosition() override;

        void setPosition(sf::Vector2f position) override;

    protected:
        sf::RectangleShape _brick;
    };
}