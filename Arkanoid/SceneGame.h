#pragma once
#include "IScene.h"
#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"
#include <list>
#include "AppSettings.h"

namespace Arkanoid::Scene::Game {
	class SceneGame: public Interface::IScene
	{
	public:
		SceneGame();

		// Унаследовано через IScene
		Scene::SceneCommand handleInput(sf::Event& event) override;
		Scene::SceneCommand update(float dt) override;
		void draw(sf::RenderWindow& window) override;
	private:

		void handleWallCollision();
		void handleBallBrickCollision();
		void handlePaddleCollision();
		

		sf::RectangleShape background;

		std::unique_ptr<Arkanoid::Game::Paddle> _paddle;

		std::unique_ptr < Arkanoid::Game::Ball> _ball;

		std::list<std::unique_ptr<Arkanoid::Game::Brick>> collidableBrick{};
	};
}