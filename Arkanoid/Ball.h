#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "AppSettings.h"

namespace Arkanoid::Game {
    class Ball : public GameObject
    {
    public:
        Ball(float radius, sf::Vector2f pos);

        void bounceX();
        void bounceY();

        sf::Vector2f getPosition() const;
        void setPosition(sf::Vector2f pos);

        sf::Vector2f getVelosity() const;
        void setVelosity(sf::Vector2f vel);

        // Унаследовано через GameObject
        void drow(sf::RenderWindow& window) override;
        sf::FloatRect getBounds() const override;
        void update(float dt) override;
        ObjectType getType() const override;
        void onCollision(GameObject& other) override;
    protected:
        sf::CircleShape _ball;
        sf::Vector2f _moveVector {-1,-1};
        float _speed = Arkanoid::App::Settings::GAME_BALL_SPEED;
    };
}
