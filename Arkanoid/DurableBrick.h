#pragma once
#include "Brick.h"
namespace Arkanoid::Game {
    class DurableBrick :
        public Brick
    {
    public:
        DurableBrick(const std::vector<sf::Color>& damageColor, sf::Vector2f position);
        DurableBrick(const std::vector<sf::Color>& damageColor, sf::Vector2f position, sf::Vector2f size);

        bool onHit() override;

    private:
        int hitPoint;
        std::vector<sf::Color> _damageColor;
    };
}