#pragma once
#include "IBallCollisionStrategy.h"

namespace Arkanoid::Game {
    class FireCollisionStrategy :
        public Interface::IBallCollisionStrategy
    {
    public:
        // Унаследовано через IBallCollisionStrategy
        void handleCollision(Game::Ball& ball, Game::Brick& brick) override;
    };
}