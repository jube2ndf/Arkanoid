#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "AppSettings.h"

namespace Arkanoid::Game {
    class Ball : public GameObject
    {
    public:
        Ball();
        Ball(float radius, sf::Vector2f pos);

        void bounceX();
        void bounceY();

        sf::Vector2f getPosition() override;
        void setPosition(sf::Vector2f position) override;

        sf::Vector2f getVeloсity() const;
        void setVeloсity(sf::Vector2f vel);

        // Унаследовано через GameObject
        void drow(sf::RenderWindow& window) override;
        sf::FloatRect getBounds() const override;
        void update(float dt) override;
        ObjectType getType() const override;
        float GetSpeed();
    protected:
        sf::CircleShape _ball;
        sf::Vector2f _moveVector;
        float _speed;
    };
}
