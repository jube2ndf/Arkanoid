#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "AppSettings.h"
#include "IBallCollisionStrategy.h"

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
        void handleCollision(Game::Brick& brick);
        // Унаследовано через GameObject
        void draw(sf::RenderWindow& window) override;
        sf::FloatRect getBounds() const override;
        void update(float dt) override;
        ObjectType getType() const override;
        float GetSpeed();
        void setStrategy(std::unique_ptr<Arkanoid::Interface::IBallCollisionStrategy> newStrategy);
    protected:
        std::unique_ptr<Arkanoid::Interface::IBallCollisionStrategy> _strategy;
        sf::CircleShape _ball;
        sf::Vector2f _moveVector;
        float _speed;
    };
}
