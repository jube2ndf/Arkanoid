#pragma once
#include <SFML/Graphics.hpp>
#include "GameContext.h"

namespace Arkanoid::Interface
{
    class IBonus
    {
    public:
        virtual ~IBonus() = default;

        virtual void update(float dt) = 0;
        virtual void draw(sf::RenderWindow& window) = 0;
        virtual void apply(Game::GameContext& ctx) = 0;
        virtual void kill() = 0;

        virtual sf::FloatRect getBounds() const = 0;
        virtual bool isAlive() const = 0;
    };
}