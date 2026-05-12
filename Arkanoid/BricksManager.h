#pragma once
#include <list>
#include <memory>
#include "Brick.h"
#include "Ball.h"
#include "IObserver.h"


namespace Arkanoid::Game {
	class BricksManager
	{
	public:
		BricksManager();
		BricksManager(float regionBrickWidth, float regionBrickHeight);
		BricksManager(float regionBrickWidth, float regionBrickHeight, int level);

		void addObservers(Interface::IObserver* obs);

		void handleBallBrickCollision(Game::Ball& ball);

		void draw(sf::RenderWindow& window);

	private:
		const std::vector<std::vector<std::vector<int>>> levels = {
			{
				{1,1,1,1,1,1,1,1},
				{1,0,0,0,0,0,0,1},
				{1,1,1,1,1,1,1,1}
			},
			{
				{1,1,1,1,1,1,1,1},
				{1,1,1,1,1,1,1,1},
				{1,1,1,1,1,1,1,1}
			},
		};
		
		std::list<std::unique_ptr<Arkanoid::Game::Brick>> collidableBrick{};
	};
}