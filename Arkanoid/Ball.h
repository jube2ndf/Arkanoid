#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

namespace Arkanoid::Game {
    class Ball : public GameObject
    {
    public:
        Ball(float radius, sf::Vector2f pos);

        // Унаследовано через GameObject
        void drow(sf::RenderWindow& window) override;
        sf::FloatRect getBounds() const override;
        void update(float dt) override;
        ObjectType getType() const override;
        void onCollision(GameObject& other) override;
    protected:
        sf::CircleShape _ball;
        sf::Vector2f _speed;        
    };
}
