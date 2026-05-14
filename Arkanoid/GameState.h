#pragma once
#include "BrickData.h"
#include <vector>

struct GameState
{
    float ball_x{};
    float ball_y{};
    float ballmove_x{};
    float ballmove_y{};
    float px{};
    std::vector<BrickData> bricks{};
    int score{};
    GameState() {}
};