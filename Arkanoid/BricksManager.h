#pragma once
#include <list>
#include <memory>
#include "Brick.h"
#include "Ball.h"
#include "IObserver.h"
#include "GameState.h"
#include "BrickFactory.h"
#include "IBrickObserver.h"
#include "GameContext.h"


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

		int getCount();

		GameState getState();
		void setState(GameState dto);
		void addObserver(Interface::IBrickObserver* obs);
	private:
		static const std::vector<std::vector<std::vector<int>>> levels;
		
		
		std::unique_ptr<BrickFactory> _factory;
		std::vector<Interface::IBrickObserver*> _observers;

		int rows;
		int cols;
		float brickWidth;
		float brickHeight;
		int lvl;
		std::list<std::unique_ptr<Arkanoid::Game::Brick>> collidableBrick{};
	};
}