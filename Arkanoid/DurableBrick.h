#pragma once
#include "Brick.h"
#include "BrickType.h"


namespace Arkanoid::Game {
    class DurableBrick :
        public Brick
    {
    public:
        DurableBrick(const std::vector<sf::Color>& damageColor, sf::Vector2f position);
        DurableBrick(const std::vector<sf::Color>& damageColor, sf::Vector2f position, sf::Vector2f size);

        bool onHit() override;
        int getHP() override;
        BrickType getBrickType() const override;
        BrickData getData() override;

    private:
        int hitPoint;
        std::vector<sf::Color> _damageColor;
    };
}