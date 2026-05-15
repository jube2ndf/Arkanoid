#pragma once
#include "GameContext.h"

namespace Arkanoid::Interface {
	class IEffect {
    public:
        IEffect(float duration) : _duration(duration) {}

        virtual ~IEffect() = default;

        virtual void onApply(Game::GameContext& ctx) = 0;
        virtual void onExpire(Game::GameContext& ctx) = 0;

        void update(Arkanoid::Game::GameContext& ctx, float dt)
        {
            if (!_active) return;

            _elapsed += dt;

            if (_elapsed >= _duration)
            {
                onExpire(ctx);
                _active = false;
            }
        }

        bool isActive() const { return _active; }
	protected:
		float _duration;
		float _elapsed = 0.f;
		bool _active = true;
	};
}