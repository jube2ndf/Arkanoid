#pragma once
#include <SFML/System/Vector2.hpp>

namespace Arkanoid::Event
{
    struct BrickDestroyedEvent
    {
        sf::Vector2f position;
    };
}