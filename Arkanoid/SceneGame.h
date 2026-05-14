#pragma once
#include "IScene.h"
#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"
#include <list>
#include "AppSettings.h"
#include "BricksManager.h"
#include "ScoreSystem.h"
#include "SaveSystem.h"


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
		Arkanoid::Game::SaveManager _saveManager;
		GameState createMemento();
		void restoreFromMemento(const GameState& state);

		void handleWallCollision();
		void handlePaddleCollision();

		Arkanoid::Game::ScoreSystem _scoreObserver;
		Arkanoid::Game::BricksManager _managerBrick;

		sf::RectangleShape background;

		std::unique_ptr<Arkanoid::Game::Paddle> _paddle;

		std::unique_ptr < Arkanoid::Game::Ball> _ball;
	};
}