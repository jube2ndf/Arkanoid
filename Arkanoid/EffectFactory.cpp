#include "EffectFactory.h"
#include "FireBallEffect.h"
#include "PaddleStateEffect.h"
#include<iostream>

std::unique_ptr<Arkanoid::Interface::IEffect> Arkanoid::Game::EffectFactory::create(EffectType type)
{
	int i = static_cast<int>(type);
	if (
		type == Arkanoid::Game::EffectType::RUNDOM ||
		type == Arkanoid::Game::EffectType::COUNT
		)
	{
		i = 1;// rand() % (static_cast<int>(Arkanoid::Game::EffectType::COUNT) - 1) + 1;
		std::cout << i << "\n";
	}

	switch (static_cast<Arkanoid::Game::EffectType>(i))
	{
	case Arkanoid::Game::EffectType::FireBall:
		return this->createFireBall();
	case Arkanoid::Game::EffectType::BigPaddle:
		return this->createSizePaddle();
	case Arkanoid::Game::EffectType::FasterPaddle:
		return this->createSpeedPaddle();
	}
}

std::unique_ptr<Arkanoid::Interface::IEffect> Arkanoid::Game::EffectFactory::createFireBall()
{
    return std::make_unique<FireBallEffect>(20);
}

std::unique_ptr<Arkanoid::Interface::IEffect> Arkanoid::Game::EffectFactory::createSizePaddle()
{
	return std::make_unique<PaddleStateEffect>(PaddleState{ 2,1 });
}

std::unique_ptr<Arkanoid::Interface::IEffect> Arkanoid::Game::EffectFactory::createSpeedPaddle()
{
	return std::make_unique<PaddleStateEffect>(PaddleState{ 1, 2 });
}
