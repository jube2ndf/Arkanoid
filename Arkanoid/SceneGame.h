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
#include "IBonus.h"
#include "IEffect.h"
#include "GameContext.h"
#include "IBrickObserver.h"
#include "EffectFactory.h"


namespace Arkanoid::Scene::Game {
	class SceneGame: 
		public Interface::IScene,
		public Arkanoid::Interface::IBrickObserver
	{
	public:
		SceneGame();
		// Унаследовано через IScene
		Scene::SceneCommand handleInput(sf::Event& event) override;
		Scene::SceneCommand update(float dt) override;
		void draw(sf::RenderWindow& window) override;
		// Унаследовано через IBrickObserver
		void onBrickDestroyed(const Event::BrickDestroyedEvent& event) override;
	private:
		Arkanoid::Game::SaveManager _saveManager;
		Arkanoid::Game::GameContext _context;
		GameState createMemento();
		void restoreFromMemento(const GameState& state);

		Scene::SceneCommand handleWallCollision();
		void handlePaddleCollision();
		void handleBonusCollision();

		void clearBonus();
		void clearEffects();

		std::vector<std::unique_ptr<Interface::IBonus>> _bonuses;
		std::vector<std::unique_ptr<Interface::IEffect>> _effects;
		Arkanoid::Game::ScoreSystem _scoreObserver;
		Arkanoid::Game::EffectFactory _effectsFactory;
		Arkanoid::Game::BricksManager _managerBrick;

		sf::RectangleShape background;

		std::unique_ptr<Arkanoid::Game::Paddle> _paddle;

		std::unique_ptr < Arkanoid::Game::Ball> _ball;

		
	};
}