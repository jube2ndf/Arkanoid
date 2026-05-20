#pragma once
#include "IEffect.h"
namespace Arkanoid::Game {
    class FireBallEffect :
        public Interface::IEffect
    {
    public:
        FireBallEffect();
        FireBallEffect(float duration);
        // Унаследовано через IEffect
        void onApply(Game::GameContext& ctx) override;
        void onExpire(Game::GameContext& ctx) override;
    };
}