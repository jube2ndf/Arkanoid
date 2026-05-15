#pragma once
namespace Arkanoid::Game
{
	class Ball;
	class Brick;
}
namespace Arkanoid::Interface {
	class IBallCollisionStrategy {
	public:
		virtual void handleCollision(
			Game::Ball& ball,
			Game::Brick& brick
		) = 0;
	};
}