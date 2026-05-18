#include "FireBallEffect.h"
#include "FireCollisionStrategy.h"
#include "NormalCollisionStrategy.h"

Arkanoid::Game::FireBallEffect::FireBallEffect(float duration)
	:IEffect(duration)
{
	
}

void Arkanoid::Game::FireBallEffect::onApply(Game::GameContext& ctx)
{
	ctx.ball->setStrategy(
		std::make_unique<FireCollisionStrategy>()
	);
}

void Arkanoid::Game::FireBallEffect::onExpire(Game::GameContext & ctx)
{
	ctx.ball->setStrategy(
		std::make_unique<NormalCollisionStrategy>()
	);
}
