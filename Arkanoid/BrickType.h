#pragma once
namespace Arkanoid::Game {
    enum class BrickType {
        EMPTY = 0,
        NORMAL,     // 1 hit
        STRONG,   // 2 hits

        RANDOM
    };
}