#pragma once
#include <SFML/Graphics.hpp>
#include "Brick.h"
#include "BrickType.h"

constexpr auto MAX_BRICK_HITS = 10;

namespace Arkanoid::Game {
	class BrickFactory
	{
    public:
        BrickFactory() = default;
        BrickFactory(const BrickFactory&) = default;
        BrickFactory(sf::Vector2f size);

        std::unique_ptr<Brick> create(BrickType type, sf::Vector2f position);
        std::unique_ptr<Brick> create(BrickData dto);

    private:
        std::unique_ptr<Brick> createNormal(BrickData dto);
        std::unique_ptr<Brick> createDurable(BrickData dto);


        sf::Vector2f _size;

        const int maxHits = MAX_BRICK_HITS;
        std::vector<sf::Color> _colors;

        sf::Color getColorForHits(int hits, int maxHits) {
            float percent = static_cast<float>(hits) / maxHits;
            return sf::Color(
                static_cast<sf::Uint8>(255 * (1 - percent)),
                static_cast<sf::Uint8>(255 * percent),
                0
            );
        }
	};
}