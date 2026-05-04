#pragma once
#include "SceneFactory.h"

namespace Arkanoid::Scene {
	class SceneManager
	{
	public:
		SceneManager(const SceneManager&) = delete;
		SceneManager& operator=(const SceneManager&) = delete;

		SceneManager(Scene::SceneFactory& factory);

		void HandelInput(sf::Event& event);
		void Update(float dt);
		void Draw(sf::RenderWindow& window);

		float restart();

	protected:
		void requestPop();
		void requestPush(EnumScene::SceneType id);
		void requestClear();
		void processCommand();

		sf::Clock game_clock;
		Scene::SceneFactory _factory;
		std::vector<Scene::SceneCommand> _commands;
		std::vector <std::unique_ptr<Interface::IScene>> _scenes;
	};
}