#pragma once
#include "Ball.h"
#include "Paddle.h"
#include "BricksManager.h"
#include "ScoreSystem.h"

namespace Arkanoid::Interface
{
    class IEffect;
}
namespace Arkanoid::Game
{
    struct GameContext
    {
        Ball* ball;
        Paddle* paddle;
        ScoreSystem* score;
        std::vector<std::unique_ptr<Interface::IEffect>>* effects;
    };
}