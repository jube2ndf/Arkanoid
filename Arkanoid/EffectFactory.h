#pragma once
#include "IEffect.h"
#include "EffectType.h"

namespace Arkanoid::Game {
	class EffectFactory
	{
	public:
		std::unique_ptr<Interface::IEffect> create(EffectType type);
	private:
		std::unique_ptr<Interface::IEffect> createFireBall();
		std::unique_ptr<Interface::IEffect> createSizePaddle();
		std::unique_ptr<Interface::IEffect> createSpeedPaddle();
	};
}