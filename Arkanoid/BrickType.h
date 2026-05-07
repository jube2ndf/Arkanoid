#pragma once
namespace Arkanoid::Game {
    enum class BrickType {
        NORMAL,     // 1 hit
        STRONG_2,   // 2 hits
        STRONG_3,   // 3 hits

        RANDOM, // 1-10 hits
    };
}