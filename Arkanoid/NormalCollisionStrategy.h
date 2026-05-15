#pragma once
#include "IBallCollisionStrategy.h"
#include "Ball.h"
#include "Brick.h"

namespace Arkanoid::Game {
    class NormalCollisionStrategy :
        public Interface::IBallCollisionStrategy
    {
    public:
        NormalCollisionStrategy() = default;
        void handleCollision(Ball& ball, Brick& brick) override {
            if (!ball.getBounds().intersects(brick.getBounds()))
                return;
            auto ballBounds = ball.getBounds();
            auto brickBounds = brick.getBounds();

            bool hitFromLeft = ball.getPosition().x + ballBounds.width <= brickBounds.left;
            bool hitFromRight = ball.getPosition().x >= brickBounds.left + brickBounds.width;

            if (hitFromLeft || hitFromRight)
            {
                ball.bounceX();
            }
            else
            {
                ball.bounceY();
            }
        };
    };
}