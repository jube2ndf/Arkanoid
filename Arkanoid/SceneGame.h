#pragma once
#include "IScene.h"
#include "Ball.h"
#include "Paddle.h"
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

		void handlePaddleCollision();
		

		sf::RectangleShape background;

		Arkanoid::Game::Paddle _paddle{ 
			200,
			20, 
			sf::Vector2f(static_cast<int>(Arkanoid::App::Settings::WINDOW_WIDTH / 2), Arkanoid::App::Settings::WINDOW_HEIGTH - 10) 
		};

		Arkanoid::Game::Ball _ball{
			Arkanoid::App::Settings::GAME_BALL_RADIUS,
			sf::Vector2f(static_cast<int>(Arkanoid::App::Settings::WINDOW_WIDTH / 2), static_cast<int>((Arkanoid::App::Settings::WINDOW_HEIGTH / 2)))
		};

		std::vector<Arkanoid::Game::GameObject*> collidableObjects{};
	};
}