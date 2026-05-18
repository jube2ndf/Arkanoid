#pragma once
#include "PaddleState.h"
#include "IEffect.h"
namespace Arkanoid::Game {
    class PaddleStateEffect :
        public Interface::IEffect
    {
    public:
        PaddleStateEffect(PaddleState state);
        // Унаследовано через IEffect
        void onApply(Game::GameContext& ctx) override;
        void onExpire(Game::GameContext& ctx) override;
    protected:
        PaddleState _state;
    };
}