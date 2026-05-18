#include "PaddleStateEffect.h"

Arkanoid::Game::PaddleStateEffect::PaddleStateEffect(PaddleState state)
	:IEffect(20)
{
	this->_state = state;
}

void Arkanoid::Game::PaddleStateEffect::onApply(Game::GameContext& ctx)
{
	ctx.paddle->setState(
		this->_state
	);
}

void Arkanoid::Game::PaddleStateEffect::onExpire(Game::GameContext & ctx)
{
	ctx.paddle->setState({
		1.f,
		1.f
	});
}
